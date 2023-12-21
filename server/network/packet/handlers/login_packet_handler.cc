#include "login_packet_handler.hh"

#include "server/turbo_server.hh"
#include "server/utils/nbt/nbt.hh"
#include "server/utils/nbt/tag/nbt_tag.hh"
#include "server/utils/nbt/tag/nbt_tag_compound.hh"
#include "server/utils/nbt/tag/nbt_tag_list.hh"
#include "server/utils/nbt/tag/nbt_tag_primitive.hh"

/*
	C→S: Handshake with Next State set to 2 (login)

    C→S: Login Start
		S→C: Encryption Request
		Client auth
		C→S: Encryption Response
		Server auth, both enable encryption
    S→C: Set Compression (optional)
    S→C: Login Success
 */

void LoginPacketHandler::handle(PlayerSocket* sock, Packet& packet)
{
	switch (packet.getId())
	{
		case PacketId::Login::LOGIN_START:
			handleLoginStart(sock, packet);
			break;

		case PacketId::Login::ENCRYPTION_RESPONSE:
			handleEncryptionRes(sock, packet);
			break;

		case PacketId::Login::LOGIN_PLUGIN_RESPONSE:
			handleLoginPluginRes(sock, packet);
			break;

		default:
			break;
	}
}

void LoginPacketHandler::disconnect(PlayerSocket* sock, ChatComponent* chat)
{
	PacketBuff buff;
	buff.writeString(chat->toString());
	sock->write({ PacketId::Login::DISCONNECT, std::move(buff) });
}

void LoginPacketHandler::handleLoginStart(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	GameProfile profile;
	profile.name = data.readString();
	bool hasId = data.readByte();
	profile.uuid = hasId ? data.readUUID() : UUID::nil();

	static Logger log("LoginPacketHandler");
	log.debug("login: {}, {} {}", profile.name, hasId, profile.uuid.toString());

	if (!isNameValid(profile.name))
	{
		PacketBuff buff;
		buff.writeString(std::format(R"({{"text":"name {} is invalid"}})", profile.name));
		sock->write({ PacketId::Login::DISCONNECT, std::move(buff) });
		return;
	}

	// todo check ban
	BanManager& ban = TurboServer::get()->getBanManager();
	if (false)
	{
	}

	if (true) // todo online mode
	{
	}

	// create player
	auto player = std::make_unique<PlayerEntity>(sock);
	player->profile = profile;
	sock->player = player.get();
	TurboServer::get()->getPlayerList().addPlayer(std::move(player));

	const VelocityConfig& velocityConfig = TurboServer::get()->getConfigManager().getVelocityConfig();
	if (velocityConfig.enabled)
	{
		PacketBuff buff;
		buff.writeVarint(999);
		buff.writeString("velocity:player_info");
		buff.writeByte(4);
		sock->write({ PacketId::Login::LOGIN_PLUGIN_REQUEST, std::move(buff) });
		return;
	}

	const NetworkConfig& networkConfig = TurboServer::get()->getConfigManager().getNetworkConfig();
	setCompression(sock, networkConfig.compressionThreshold);
	log.debug("compression set for {}", sock->getAddress());

	success(sock, profile);
	log.debug("login success sent to {}", sock->getAddress());

	{
		PacketBuff buff;
		buff.writeInt(sock->player->id);
		buff.writeByte(false); // hardcore
		buff.writeByte(sock->player->gameMode->getId());
		buff.writeByte(sock->player->previousGameMode->getId());
		buff.writeVarint(1); // dimension count
		buff.writeString("minecraft:world"); // identifierArray

		std::map<std::string, std::unique_ptr<NbtTag>> registryTags;

		std::map<std::string, std::unique_ptr<NbtTag>> registryTagsChat;
		registryTagsChat["type"] = std::make_unique<NbtTagString>("type", "minecraft:chat_type");

		registryTags["minecraft:chat_type"] = std::make_unique<NbtTagCompound>("minecraft:chat_type", registryTagsChat);
		std::unique_ptr<NbtTag> registry = std::make_unique<NbtTagCompound>("", registryTags);
		NBT::write(buff, registry);

		buff.writeString("minecraft:overworld"); // dimension type
		buff.writeString("minecraft:world"); // dimension name
		buff.writeLongU(UUID::random().getLo()); // hashed seed
		buff.writeVarint(33); // max players
		buff.writeVarint(4); // view distance
		buff.writeVarint(4); // simulation distance
		buff.writeByte(false); // reduced debug info
		buff.writeByte(true); // enable respawn screen
		buff.writeByte(false); // debug
		buff.writeByte(true); // flat
		buff.writeByte(false); // has death location
		//		buff.writeString("minecraft:world"); // death dimension
		//		buff.writeLongU(0); // death pos
		buff.writeVarint(5); // portal cooldown

		sock->write({ PacketId::Play::LOGIN, std::move(buff) });
	}
}

void LoginPacketHandler::handleEncryptionRes(PlayerSocket* sock, Packet& packet)
{
}

void LoginPacketHandler::handleLoginPluginRes(PlayerSocket* sock, Packet& packet)
{
	// todo velocity proxy
	static Logger log("VelocityLoginPacketHandler");

	PacketBuff& data = packet.getData();

	const VelocityConfig& cfg = TurboServer::get()->getConfigManager().getVelocityConfig();
	if (!cfg.enabled)
	{
		PacketBuff buff;
		buff.writeString(R"({"text":"velocity compatibility disabled","color":"dark_red"})");
		sock->write({ PacketId::Login::DISCONNECT, std::move(buff) });
		return;
	}

	int msgId = data.readVarint();
	bool success = data.readByte();

	log.info("data: {}", data.toStringShort());

	int version = data.readVarint();
	std::string address = data.readString();

	UUID uuid = data.readUUID();
	std::string name = data.readString();

	struct prop
	{
		std::string name;
		std::string val;
		std::string sig;
	};
	std::vector<prop> props;

	int propLen = data.readVarint();
	for (int i = 0; i < propLen; i++)
	{
		prop p;
		p.name = data.readString();
		p.val = data.readString();
		p.sig = data.readByte() ? data.readString() : "";
	}

	log.info("login plugin packet: msgId={} success={} ver={} addr={}:{} uuid={} name={} props={}", msgId, success, version, address.size(),
	         address.c_str(), uuid.toString(), name, props.size());
}

void LoginPacketHandler::setCompression(PlayerSocket* sock, int threshold)
{
	sock->compressionThreshold = threshold;

	PacketBuff buff;
	buff.writeVarint(std::max(0, sock->compressionThreshold));
	sock->write({ PacketId::Login::SET_COMPRESSION, std::move(buff) });
	sock->compressionEnabled = true;
}

void LoginPacketHandler::success(PlayerSocket* sock, GameProfile& profile)
{
	PacketBuff buff;
	buff.writeUUID(profile.uuid);
	buff.writeString(profile.name);
	buff.writeVarint(0);
	sock->write({ PacketId::Login::LOGIN_SUCCESS, std::move(buff) });

	sock->setState(PLAY);
}


bool LoginPacketHandler::isNameValid(const std::string& name)
{
	for (char c : name)
		if (c <= 32 || c >= 127)
			return false;

	return name.length() >= 3 && name.length() <= 16;
}
