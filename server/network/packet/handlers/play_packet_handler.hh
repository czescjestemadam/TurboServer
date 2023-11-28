#pragma once
#include "packet_handler.hh"
#include "../../socket/player_socket.hh"

class PlayPacketHandler : public PacketHandler
{
	PlayerEntity* player;

public:
	explicit PlayPacketHandler(PlayerSocket* sock);

	void handle(Packet& packet) override;
	void disconnect(ChatComponent chat) override;

private:
	void handleConfirmTeleport(Packet& packet);
	void handleQueryBlockEntityTag(Packet& packet);
	void handleChangeDifficulty(Packet& packet);
	void handleMessageAck(Packet& packet);
	void handleChatCommand(Packet& packet);
	void handleChatMessage(Packet& packet);
	void handlePlayerSession(Packet& packet);
	void handleClientCommand(Packet& packet);
	void handleClientInfo(Packet& packet);
	void handleCommandSuggestionReq(Packet& packet);
	void handleClickContainerButton(Packet& packet);
	void handleClickContainer(Packet& packet);
	void handleCloseContainer(Packet& packet);
	void handlePluginMessage(Packet& packet);
	void handleEditBook(Packet& packet);
	void handleQueryEntityTag(Packet& packet);
	void handleInteract(Packet& packet);
	void handleJigsawGenerate(Packet& packet);
	void handleKeepAlive(Packet& packet);
	void handleLockDifficulty(Packet& packet);
	void handleSetPlayerPos(Packet& packet);
	void handleSetPlayerPosAndRot(Packet& packet);
	void handleSetPlayerRot(Packet& packet);
	void handleSetPlayerOnGround(Packet& packet);
	void handleMoveVehicle(Packet& packet);
	void handlePaddleBoat(Packet& packet);
	void handlePickItem(Packet& packet);
	void handlePlaceRecipe(Packet& packet);
	void handlePlayerAbilities(Packet& packet);
	void handlePlayerAction(Packet& packet);
	void handlePlayerCommand(Packet& packet);
	void handlePlayerInput(Packet& packet);
	void handlePong(Packet& packet);
	void handleChangeRecipeBookSettings(Packet& packet);
	void handleSetSeenRecipe(Packet& packet);
	void handleRenameItem(Packet& packet);
	void handleResourcePack(Packet& packet);
	void handleSeenAdvancements(Packet& packet);
	void handleSelectTrade(Packet& packet);
	void handleSetBeaconEffect(Packet& packet);
	void handleSetHeldItem(Packet& packet);
	void handleProgramCommandBlock(Packet& packet);
	void handleProgramCommandBlockMinecart(Packet& packet);
	void handleSetCreativeModeSlot(Packet& packet);
	void handleProgramJigsawBlock(Packet& packet);
	void handleProgramStructureBlock(Packet& packet);
	void handleUpdateSign(Packet& packet);
	void handleSwingArm(Packet& packet);
	void handleTeleportToEntity(Packet& packet);
	void handleUseItemOn(Packet& packet);
	void handleUseItem(Packet& packet);
};
