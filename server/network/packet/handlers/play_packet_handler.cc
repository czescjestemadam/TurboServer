#include "play_packet_handler.hh"
#include "../packet_id.hh"

void PlayPacketHandler::handle(PlayerSocket* sock, Packet& packet)
{
	using PacketId::Play::TS;

	switch (packet.getId())
	{
		case TS::CONFIRM_TELEPORTATION:
			handleConfirmTeleport(sock, packet);
			break;

		case TS::QUERY_BLOCK_ENTITY_TAG:
			handleQueryBlockEntityTag(sock, packet);
			break;

		case TS::CHANGE_DIFFICULTY_TS:
			handleChangeDifficulty(sock, packet);
			break;

		case TS::MESSAGE_ACKNOWLEDGEMENT:
			handleMessageAck(sock, packet);
			break;

		case TS::CHAT_COMMAND:
			handleChatCommand(sock, packet);
			break;

		case TS::CHAT_MESSAGE:
			handleChatMessage(sock, packet);
			break;

		case TS::PLAYER_SESSION:
			handlePlayerSession(sock, packet);
			break;

		case TS::CLIENT_COMMAND:
			handleClientCommand(sock, packet);
			break;

		case TS::CLIENT_INFORMATION:
			handleClientInfo(sock, packet);
			break;

		case TS::COMMAND_SUGGESTIONS_REQUEST:
			handleCommandSuggestionReq(sock, packet);
			break;

		case TS::CLICK_CONTAINER_BUTTON:
			handleClickContainerButton(sock, packet);
			break;

		case TS::CLICK_CONTAINER:
			handleClickContainer(sock, packet);
			break;

		case TS::CLOSE_CONTAINER_TS:
			handleCloseContainer(sock, packet);
			break;

		case TS::PLUGIN_MESSAGE_TS:
			handlePluginMessage(sock, packet);
			break;

		case TS::EDIT_BOOK:
			handleEditBook(sock, packet);
			break;

		case TS::QUERY_ENTITY_TAG:
			handleQueryEntityTag(sock, packet);
			break;

		case TS::INTERACT:
			handleInteract(sock, packet);
			break;

		case TS::JIGSAW_GENERATE:
			handleJigsawGenerate(sock, packet);
			break;

		case TS::KEEP_ALIVE_TS:
			handleKeepAlive(sock, packet);
			break;

		case TS::LOCK_DIFFICULTY:
			handleLockDifficulty(sock, packet);
			break;

		case TS::SET_PLAYER_POSITION:
			handleSetPlayerPos(sock, packet);
			break;

		case TS::SET_PLAYER_POSITION_AND_ROTATION:
			handleSetPlayerPosAndRot(sock, packet);
			break;

		case TS::SET_PLAYER_ROTATION:
			handleSetPlayerRot(sock, packet);
			break;

		case TS::SET_PLAYER_ON_GROUND:
			handleSetPlayerOnGround(sock, packet);
			break;

		case TS::MOVE_VEHICLE_TS:
			handleMoveVehicle(sock, packet);
			break;

		case TS::PADDLE_BOAT:
			handlePaddleBoat(sock, packet);
			break;

		case TS::PICK_ITEM:
			handlePickItem(sock, packet);
			break;

		case TS::PLACE_RECIPE:
			handlePlaceRecipe(sock, packet);
			break;

		case TS::PLAYER_ABILITIES_TS:
			handlePlayerAbilities(sock, packet);
			break;

		case TS::PLAYER_ACTION:
			handlePlayerAction(sock, packet);
			break;

		case TS::PLAYER_COMMAND:
			handlePlayerCommand(sock, packet);
			break;

		case TS::PLAYER_INPUT:
			handlePlayerInput(sock, packet);
			break;

		case TS::PONG:
			handlePong(sock, packet);
			break;

		case TS::CHANGE_RECIPE_BOOK_SETTINGS:
			handleChangeRecipeBookSettings(sock, packet);
			break;

		case TS::SET_SEEN_RECIPE:
			handleSetSeenRecipe(sock, packet);
			break;

		case TS::RENAME_ITEM:
			handleRenameItem(sock, packet);
			break;

		case TS::RESOURCE_PACK_TS:
			handleResourcePack(sock, packet);
			break;

		case TS::SEEN_ADVANCEMENTS:
			handleSeenAdvancements(sock, packet);
			break;

		case TS::SELECT_TRADE:
			handleSelectTrade(sock, packet);
			break;

		case TS::SET_BEACON_EFFECT:
			handleSetBeaconEffect(sock, packet);
			break;

		case TS::SET_HELD_ITEM_TS:
			handleSetHeldItem(sock, packet);
			break;

		case TS::PROGRAM_COMMAND_BLOCK:
			handleProgramCommandBlock(sock, packet);
			break;

		case TS::PROGRAM_COMMAND_BLOCK_MINECART:
			handleProgramCommandBlockMinecart(sock, packet);
			break;

		case TS::SET_CREATIVE_MODE_SLOT:
			handleSetCreativeModeSlot(sock, packet);
			break;

		case TS::PROGRAM_JIGSAW_BLOCK:
			handleProgramJigsawBlock(sock, packet);
			break;

		case TS::PROGRAM_STRUCTURE_BLOCK:
			handleProgramStructureBlock(sock, packet);
			break;

		case TS::UPDATE_SIGN:
			handleUpdateSign(sock, packet);
			break;

		case TS::SWING_ARM:
			handleSwingArm(sock, packet);
			break;

		case TS::TELEPORT_TO_ENTITY:
			handleTeleportToEntity(sock, packet);
			break;

		case TS::USE_ITEM_ON:
			handleUseItemOn(sock, packet);
			break;

		case TS::USE_ITEM:
			handleUseItem(sock, packet);
			break;

		default:
			break;
	}
}

void PlayPacketHandler::disconnect(PlayerSocket* sock, ChatComponent* chat)
{
	PacketBuff buff;
	buff.writeString(chat->toString());
	sock->write({ PacketId::Play::DISCONNECT, std::move(buff) });
}


void PlayPacketHandler::handleConfirmTeleport(PlayerSocket* sock, Packet& packet)
{
	int id = packet.getData().readVarint();


}

void PlayPacketHandler::handleQueryBlockEntityTag(PlayerSocket* sock, Packet& packet)
{

}

void PlayPacketHandler::handleChangeDifficulty(PlayerSocket* sock, Packet& packet)
{
	// singleplayer only
}

void PlayPacketHandler::handleMessageAck(PlayerSocket* sock, Packet& packet)
{
	int msgCount = packet.getData().readVarint();
}

void PlayPacketHandler::handleChatCommand(PlayerSocket* sock, Packet& packet)
{

}

void PlayPacketHandler::handleChatMessage(PlayerSocket* sock, Packet& packet)
{

}

void PlayPacketHandler::handlePlayerSession(PlayerSocket* sock, Packet& packet)
{

}

void PlayPacketHandler::handleClientCommand(PlayerSocket* sock, Packet& packet)
{
	const int id = packet.getData().readVarint();
	if (id == 0) // respawn
	{

	}
	else if (id == 1) // request stats
	{

	}
}

void PlayPacketHandler::handleClientInfo(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	std::string locale = data.readString();
	byte_t viewDistance = data.readByte();
	int chatMode = data.readVarint();
	bool chatColors = data.readByte();
	byte_t skinParts = data.readByte();
	int mainHand = data.readVarint();
	bool textFiltering = data.readByte();
	bool allowServerListings = data.readByte();


}

void PlayPacketHandler::handleCommandSuggestionReq(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	int id = data.readVarint();
	std::string text = data.readString();


}

void PlayPacketHandler::handleClickContainerButton(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	byte_t windowId = data.readByte();
	byte_t buttonId = data.readByte();


}

void PlayPacketHandler::handleClickContainer(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	byte_t windowId = data.readByte();
	int stateId = data.readVarint();
	short slot = data.readShort();
	byte_t button = data.readByte();
	int mode = data.readVarint();

	int len = data.readVarint();
	short slotNum[len];
	// slot slotData[len];
	// todo
}

void PlayPacketHandler::handleCloseContainer(PlayerSocket* sock, Packet& packet)
{
	byte_t windowId = packet.getData().readByte();
}

void PlayPacketHandler::handlePluginMessage(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	std::string channel = data.readString();
	// rest bytes in data;
}

void PlayPacketHandler::handleEditBook(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	int slot = data.readVarint();
	const int pageNum = data.readVarint();
	std::string pages[pageNum];
	for (int i = 0; i < pageNum; ++i)
		pages[i] = data.readString();

	std::string title;

	if (data.readByte()) // hasTitle
		title = data.readString();
}

void PlayPacketHandler::handleQueryEntityTag(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	int transactionId = data.readVarint();
	int entityId = data.readVarint();
}

void PlayPacketHandler::handleInteract(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	int entityId = data.readVarint();
	int type = data.readVarint();
	Vec3f target;
	if (type == 2)
		target = Vec3f(data.readFloat(), data.readFloat(), data.readFloat());

	int hand = -1;
	if (type != 1)
		hand = data.readVarint();

	bool sneaking = data.readByte();

}

void PlayPacketHandler::handleJigsawGenerate(PlayerSocket* sock, Packet& packet)
{

}

void PlayPacketHandler::handleKeepAlive(PlayerSocket* sock, Packet& packet)
{
	long id = packet.getData().readLong();
}

void PlayPacketHandler::handleLockDifficulty(PlayerSocket* sock, Packet& packet)
{
	// singleplayer only
}

void PlayPacketHandler::handleSetPlayerPos(PlayerSocket* sock, Packet& packet)
{
	// todo antycheat
	PacketBuff& data = packet.getData();

	double x = data.readDouble();
	double y = data.readDouble();
	double z = data.readDouble();
	bool onGround = data.readByte();
}

void PlayPacketHandler::handleSetPlayerPosAndRot(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	double x = data.readDouble();
	double y = data.readDouble();
	double z = data.readDouble();
	float yaw = data.readFloat();
	float pitch = data.readFloat();
	bool onGround = data.readByte();
}

void PlayPacketHandler::handleSetPlayerRot(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	float yaw = data.readFloat();
	float pitch = data.readFloat();
	bool onGround = data.readByte();
}

void PlayPacketHandler::handleSetPlayerOnGround(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	bool onGround = data.readByte();
}

void PlayPacketHandler::handleMoveVehicle(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	double x = data.readDouble();
	double y = data.readDouble();
	double z = data.readDouble();
	float yaw = data.readFloat();
	float pitch = data.readFloat();
}

void PlayPacketHandler::handlePaddleBoat(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	bool left = data.readByte();
	bool right = data.readByte();
}

void PlayPacketHandler::handlePickItem(PlayerSocket* sock, Packet& packet)
{
	int slotToUse = packet.getData().readVarint();
}

void PlayPacketHandler::handlePlaceRecipe(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	byte_t windowId = data.readByte();
	Identifier recipe = data.readIdentifier();
	bool makeAll = data.readByte();
}

void PlayPacketHandler::handlePlayerAbilities(PlayerSocket* sock, Packet& packet)
{
	byte_t abilities = packet.getData().readByte();
}

void PlayPacketHandler::handlePlayerAction(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	int status = data.readVarint();
	Vec3i pos = data.readPosition();
	byte_t face = data.readByte();
	int sequence = data.readVarint();
}

void PlayPacketHandler::handlePlayerCommand(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	int entityId = data.readVarint();
	int actionId = data.readVarint();
	int jumpBoost = data.readVarint();
}

void PlayPacketHandler::handlePlayerInput(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	float sideways = data.readFloat();
	float forward = data.readFloat();
	byte_t flags = data.readByte();
}

void PlayPacketHandler::handlePong(PlayerSocket* sock, Packet& packet)
{
	int id = packet.getData().readInt();
}

void PlayPacketHandler::handleChangeRecipeBookSettings(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	int bookId = data.readVarint();
	bool bookOpen = data.readByte();
	bool filterActive = data.readByte();
}

void PlayPacketHandler::handleSetSeenRecipe(PlayerSocket* sock, Packet& packet)
{
	Identifier recipe = packet.getData().readIdentifier();
}

void PlayPacketHandler::handleRenameItem(PlayerSocket* sock, Packet& packet)
{
	std::string name = packet.getData().readString();
}

void PlayPacketHandler::handleResourcePack(PlayerSocket* sock, Packet& packet)
{
	int result = packet.getData().readVarint();
}

void PlayPacketHandler::handleSeenAdvancements(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	const int action = data.readVarint();
	Identifier tab = Identifier::nil();
	if (action == 0)
		tab = data.readIdentifier();
}

void PlayPacketHandler::handleSelectTrade(PlayerSocket* sock, Packet& packet)
{
	int selectedSlot = packet.getData().readVarint();
}

void PlayPacketHandler::handleSetBeaconEffect(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	bool hasPrimary = data.readByte();
	int primary = data.readVarint();
	bool hasSecondary = data.readByte();
	int secondary = data.readVarint();
}

void PlayPacketHandler::handleSetHeldItem(PlayerSocket* sock, Packet& packet)
{
	short slot = packet.getData().readShort();
}

void PlayPacketHandler::handleProgramCommandBlock(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	Vec3i pos = data.readPosition();
	std::string cmd = data.readString();
	int mode = data.readVarint();
	byte_t flags = data.readByte();
}

void PlayPacketHandler::handleProgramCommandBlockMinecart(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	int entityId = data.readVarint();
	std::string cmd = data.readString();
	bool trackOutput = data.readByte();
}

void PlayPacketHandler::handleSetCreativeModeSlot(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	short slot = data.readShort();
	// todo slot
}

void PlayPacketHandler::handleProgramJigsawBlock(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	Vec3i pos = data.readPosition();
	Identifier name = data.readIdentifier();
	Identifier target = data.readIdentifier();
	Identifier pool = data.readIdentifier();
	std::string finalState = data.readString();
	std::string jointState = data.readString();
}

void PlayPacketHandler::handleProgramStructureBlock(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	Vec3i pos = data.readPosition();
	int action = data.readVarint();
	int mode = data.readVarint();
	std::string name = data.readString();
	byte_t offsetX = data.readByte();
	byte_t offsetY = data.readByte();
	byte_t offsetZ = data.readByte();
	byte_t sizeX = data.readByte();
	byte_t sizeY = data.readByte();
	byte_t sizeZ = data.readByte();
	int mirror = data.readVarint();
	int rotation = data.readVarint();
	std::string metadata = data.readString();
	float integrity = data.readFloat();
	long seed = data.readVarlong();
	byte_t flags = data.readByte();
}

void PlayPacketHandler::handleUpdateSign(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	Vec3i pos = data.readPosition();
	bool isFront = data.readByte();
	std::string lines[4] = { data.readString(), data.readString(), data.readString(), data.readString() };
}

void PlayPacketHandler::handleSwingArm(PlayerSocket* sock, Packet& packet)
{
	int hand = packet.getData().readVarint();
}

void PlayPacketHandler::handleTeleportToEntity(PlayerSocket* sock, Packet& packet)
{
	// spectator only
	UUID target = packet.getData().readUUID();
}

void PlayPacketHandler::handleUseItemOn(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	int hand = data.readVarint();
	Vec3i pos = data.readPosition();
	int face = data.readVarint();
	float cursorPosX = data.readFloat();
	float cursorPosY = data.readFloat();
	float cursorPosZ = data.readFloat();
	bool insideBlock = data.readByte();
	int sequence = data.readVarint();
}

void PlayPacketHandler::handleUseItem(PlayerSocket* sock, Packet& packet)
{
	PacketBuff& data = packet.getData();

	int hand = data.readVarint();
	int sequence = data.readVarint();
}
