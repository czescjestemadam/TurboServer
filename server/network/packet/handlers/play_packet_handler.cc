#include "play_packet_handler.hh"

PlayPacketHandler::PlayPacketHandler(PlayerSocket* sock) : PacketHandler(sock), player(sock->player)
{
}

void PlayPacketHandler::handle(Packet& packet)
{
	using PacketId::Play::TS;

	switch (packet.getId())
	{
		case TS::CONFIRM_TELEPORTATION:
			handleConfirmTeleport(packet);
			break;

		case TS::QUERY_BLOCK_ENTITY_TAG:
			handleQueryBlockEntityTag(packet);
			break;

		case TS::CHANGE_DIFFICULTY_TS:
			handleChangeDifficulty(packet);
			break;

		case TS::MESSAGE_ACKNOWLEDGEMENT:
			handleMessageAck(packet);
			break;

		case TS::CHAT_COMMAND:
			handleChatCommand(packet);
			break;

		case TS::CHAT_MESSAGE:
			handleChatMessage(packet);
			break;

		case TS::PLAYER_SESSION:
			handlePlayerSession(packet);
			break;

		case TS::CLIENT_COMMAND:
			handleClientCommand(packet);
			break;

		case TS::CLIENT_INFORMATION:
			handleClientInfo(packet);
			break;

		case TS::COMMAND_SUGGESTIONS_REQUEST:
			handleCommandSuggestionReq(packet);
			break;

		case TS::CLICK_CONTAINER_BUTTON:
			handleClickContainerButton(packet);
			break;

		case TS::CLICK_CONTAINER:
			handleClickContainer(packet);
			break;

		case TS::CLOSE_CONTAINER_TS:
			handleCloseContainer(packet);
			break;

		case TS::PLUGIN_MESSAGE_TS:
			handlePluginMessage(packet);
			break;

		case TS::EDIT_BOOK:
			handleEditBook(packet);
			break;

		case TS::QUERY_ENTITY_TAG:
			handleQueryEntityTag(packet);
			break;

		case TS::INTERACT:
			handleInteract(packet);
			break;

		case TS::JIGSAW_GENERATE:
			handleJigsawGenerate(packet);
			break;

		case TS::KEEP_ALIVE_TS:
			handleKeepAlive(packet);
			break;

		case TS::LOCK_DIFFICULTY:
			handleLockDifficulty(packet);
			break;

		case TS::SET_PLAYER_POSITION:
			handleSetPlayerPos(packet);
			break;

		case TS::SET_PLAYER_POSITION_AND_ROTATION:
			handleSetPlayerPosAndRot(packet);
			break;

		case TS::SET_PLAYER_ROTATION:
			handleSetPlayerRot(packet);
			break;

		case TS::SET_PLAYER_ON_GROUND:
			handleSetPlayerOnGround(packet);
			break;

		case TS::MOVE_VEHICLE_TS:
			handleMoveVehicle(packet);
			break;

		case TS::PADDLE_BOAT:
			handlePaddleBoat(packet);
			break;

		case TS::PICK_ITEM:
			handlePickItem(packet);
			break;

		case TS::PLACE_RECIPE:
			handlePlaceRecipe(packet);
			break;

		case TS::PLAYER_ABILITIES_TS:
			handlePlayerAbilities(packet);
			break;

		case TS::PLAYER_ACTION:
			handlePlayerAction(packet);
			break;

		case TS::PLAYER_COMMAND:
			handlePlayerCommand(packet);
			break;

		case TS::PLAYER_INPUT:
			handlePlayerInput(packet);
			break;

		case TS::PONG:
			handlePong(packet);
			break;

		case TS::CHANGE_RECIPE_BOOK_SETTINGS:
			handleChangeRecipeBookSettings(packet);
			break;

		case TS::SET_SEEN_RECIPE:
			handleSetSeenRecipe(packet);
			break;

		case TS::RENAME_ITEM:
			handleRenameItem(packet);
			break;

		case TS::RESOURCE_PACK_TS:
			handleResourcePack(packet);
			break;

		case TS::SEEN_ADVANCEMENTS:
			handleSeenAdvancements(packet);
			break;

		case TS::SELECT_TRADE:
			handleSelectTrade(packet);
			break;

		case TS::SET_BEACON_EFFECT:
			handleSetBeaconEffect(packet);
			break;

		case TS::SET_HELD_ITEM_TS:
			handleSetHeldItem(packet);
			break;

		case TS::PROGRAM_COMMAND_BLOCK:
			handleProgramCommandBlock(packet);
			break;

		case TS::PROGRAM_COMMAND_BLOCK_MINECART:
			handleProgramCommandBlockMinecart(packet);
			break;

		case TS::SET_CREATIVE_MODE_SLOT:
			handleSetCreativeModeSlot(packet);
			break;

		case TS::PROGRAM_JIGSAW_BLOCK:
			handleProgramJigsawBlock(packet);
			break;

		case TS::PROGRAM_STRUCTURE_BLOCK:
			handleProgramStructureBlock(packet);
			break;

		case TS::UPDATE_SIGN:
			handleUpdateSign(packet);
			break;

		case TS::SWING_ARM:
			handleSwingArm(packet);
			break;

		case TS::TELEPORT_TO_ENTITY:
			handleTeleportToEntity(packet);
			break;

		case TS::USE_ITEM_ON:
			handleUseItemOn(packet);
			break;

		case TS::USE_ITEM:
			handleUseItem(packet);
			break;

		default:
			break;
	}
}

void PlayPacketHandler::disconnect(ChatComponent* chat)
{
	PacketBuff buff;
	buff.writeString(chat->toString());
	sock->write({ PacketId::Play::DISCONNECT, std::move(buff) });
}


void PlayPacketHandler::handleConfirmTeleport(Packet& packet)
{
	int id = packet.getData().readVarint();


}

void PlayPacketHandler::handleQueryBlockEntityTag(Packet& packet)
{

}

void PlayPacketHandler::handleChangeDifficulty(Packet& packet)
{
	// singleplayer only
}

void PlayPacketHandler::handleMessageAck(Packet& packet)
{
	int msgCount = packet.getData().readVarint();
}

void PlayPacketHandler::handleChatCommand(Packet& packet)
{

}

void PlayPacketHandler::handleChatMessage(Packet& packet)
{

}

void PlayPacketHandler::handlePlayerSession(Packet& packet)
{

}

void PlayPacketHandler::handleClientCommand(Packet& packet)
{
	int id = packet.getData().readVarint();
	if (id == 0) // respawn
	{

	}
	else if (id == 1) // request stats
	{

	}
}

void PlayPacketHandler::handleClientInfo(Packet& packet)
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

void PlayPacketHandler::handleCommandSuggestionReq(Packet& packet)
{
	PacketBuff& data = packet.getData();

	int id = data.readVarint();
	std::string text = data.readString();


}

void PlayPacketHandler::handleClickContainerButton(Packet& packet)
{
	PacketBuff& data = packet.getData();

	byte_t windowId = data.readByte();
	byte_t buttonId = data.readByte();


}

void PlayPacketHandler::handleClickContainer(Packet& packet)
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

void PlayPacketHandler::handleCloseContainer(Packet& packet)
{
	byte_t windowId = packet.getData().readByte();
}

void PlayPacketHandler::handlePluginMessage(Packet& packet)
{
	PacketBuff& data = packet.getData();

	std::string channel = data.readString();
	// rest bytes in data;
}

void PlayPacketHandler::handleEditBook(Packet& packet)
{
	PacketBuff& data = packet.getData();

	int slot = data.readVarint();
	int pageNum = data.readVarint();
	std::string pages[pageNum];
	for (int i = 0; i < pageNum; ++i)
		pages[i] = data.readString();

	std::string title;

	if (data.readByte()) // hasTitle
		title = data.readString();
}

void PlayPacketHandler::handleQueryEntityTag(Packet& packet)
{
	PacketBuff& data = packet.getData();

	int transactionId = data.readVarint();
	int entityId = data.readVarint();
}

void PlayPacketHandler::handleInteract(Packet& packet)
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

void PlayPacketHandler::handleJigsawGenerate(Packet& packet)
{

}

void PlayPacketHandler::handleKeepAlive(Packet& packet)
{
	long id = packet.getData().readLong();
}

void PlayPacketHandler::handleLockDifficulty(Packet& packet)
{
	// singleplayer only
}

void PlayPacketHandler::handleSetPlayerPos(Packet& packet)
{
	// todo antycheat
	PacketBuff& data = packet.getData();

	double x = data.readDouble();
	double y = data.readDouble();
	double z = data.readDouble();
	bool onGround = data.readByte();
}

void PlayPacketHandler::handleSetPlayerPosAndRot(Packet& packet)
{
	PacketBuff& data = packet.getData();

	double x = data.readDouble();
	double y = data.readDouble();
	double z = data.readDouble();
	float yaw = data.readFloat();
	float pitch = data.readFloat();
	bool onGround = data.readByte();
}

void PlayPacketHandler::handleSetPlayerRot(Packet& packet)
{
	PacketBuff& data = packet.getData();

	float yaw = data.readFloat();
	float pitch = data.readFloat();
	bool onGround = data.readByte();
}

void PlayPacketHandler::handleSetPlayerOnGround(Packet& packet)
{
	PacketBuff& data = packet.getData();

	bool onGround = data.readByte();
}

void PlayPacketHandler::handleMoveVehicle(Packet& packet)
{
	PacketBuff& data = packet.getData();

	double x = data.readDouble();
	double y = data.readDouble();
	double z = data.readDouble();
	float yaw = data.readFloat();
	float pitch = data.readFloat();
}

void PlayPacketHandler::handlePaddleBoat(Packet& packet)
{
	PacketBuff& data = packet.getData();

	bool left = data.readByte();
	bool right = data.readByte();
}

void PlayPacketHandler::handlePickItem(Packet& packet)
{
	int slotToUse = packet.getData().readVarint();
}

void PlayPacketHandler::handlePlaceRecipe(Packet& packet)
{
	PacketBuff& data = packet.getData();

	byte_t windowId = data.readByte();
	Identifier recipe = data.readIdentifier();
	bool makeAll = data.readByte();
}

void PlayPacketHandler::handlePlayerAbilities(Packet& packet)
{
	byte_t abilities = packet.getData().readByte();
}

void PlayPacketHandler::handlePlayerAction(Packet& packet)
{
	PacketBuff& data = packet.getData();

	int status = data.readVarint();
	Vec3i pos = data.readPosition();
	byte_t face = data.readByte();
	int sequence = data.readVarint();
}

void PlayPacketHandler::handlePlayerCommand(Packet& packet)
{
	PacketBuff& data = packet.getData();

	int entityId = data.readVarint();
	int actionId = data.readVarint();
	int jumpBoost = data.readVarint();
}

void PlayPacketHandler::handlePlayerInput(Packet& packet)
{
	PacketBuff& data = packet.getData();

	float sideways = data.readFloat();
	float forward = data.readFloat();
	byte_t flags = data.readByte();
}

void PlayPacketHandler::handlePong(Packet& packet)
{
	int id = packet.getData().readInt();
}

void PlayPacketHandler::handleChangeRecipeBookSettings(Packet& packet)
{
	PacketBuff& data = packet.getData();

	int bookId = data.readVarint();
	bool bookOpen = data.readByte();
	bool filterActive = data.readByte();
}

void PlayPacketHandler::handleSetSeenRecipe(Packet& packet)
{
	Identifier recipe = packet.getData().readIdentifier();
}

void PlayPacketHandler::handleRenameItem(Packet& packet)
{
	std::string name = packet.getData().readString();
}

void PlayPacketHandler::handleResourcePack(Packet& packet)
{
	int result = packet.getData().readVarint();
}

void PlayPacketHandler::handleSeenAdvancements(Packet& packet)
{
	PacketBuff& data = packet.getData();

	int action = data.readVarint();
	Identifier tab = Identifier::nil();
	if (action == 0)
		tab = data.readIdentifier();
}

void PlayPacketHandler::handleSelectTrade(Packet& packet)
{
	int selectedSlot = packet.getData().readVarint();
}

void PlayPacketHandler::handleSetBeaconEffect(Packet& packet)
{
	PacketBuff& data = packet.getData();

	bool hasPrimary = data.readByte();
	int primary = data.readVarint();
	bool hasSecondary = data.readByte();
	int secondary = data.readVarint();
}

void PlayPacketHandler::handleSetHeldItem(Packet& packet)
{
	short slot = packet.getData().readShort();
}

void PlayPacketHandler::handleProgramCommandBlock(Packet& packet)
{
	PacketBuff& data = packet.getData();

	Vec3i pos = data.readPosition();
	std::string cmd = data.readString();
	int mode = data.readVarint();
	byte_t flags = data.readByte();
}

void PlayPacketHandler::handleProgramCommandBlockMinecart(Packet& packet)
{
	PacketBuff& data = packet.getData();

	int entityId = data.readVarint();
	std::string cmd = data.readString();
	bool trackOutput = data.readByte();
}

void PlayPacketHandler::handleSetCreativeModeSlot(Packet& packet)
{
	PacketBuff& data = packet.getData();

	short slot = data.readShort();
	// todo slot
}

void PlayPacketHandler::handleProgramJigsawBlock(Packet& packet)
{
	PacketBuff& data = packet.getData();

	Vec3i pos = data.readPosition();
	Identifier name = data.readIdentifier();
	Identifier target = data.readIdentifier();
	Identifier pool = data.readIdentifier();
	std::string finalState = data.readString();
	std::string jointState = data.readString();
}

void PlayPacketHandler::handleProgramStructureBlock(Packet& packet)
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

void PlayPacketHandler::handleUpdateSign(Packet& packet)
{
	PacketBuff& data = packet.getData();

	Vec3i pos = data.readPosition();
	bool isFront = data.readByte();
	std::string lines[4] = { data.readString(), data.readString(), data.readString(), data.readString() };
}

void PlayPacketHandler::handleSwingArm(Packet& packet)
{
	int hand = packet.getData().readVarint();
}

void PlayPacketHandler::handleTeleportToEntity(Packet& packet)
{
	// spectator only
	UUID target = packet.getData().readUUID();
}

void PlayPacketHandler::handleUseItemOn(Packet& packet)
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

void PlayPacketHandler::handleUseItem(Packet& packet)
{
	PacketBuff& data = packet.getData();

	int hand = data.readVarint();
	int sequence = data.readVarint();
}
