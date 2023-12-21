#pragma once
#include "packet_handler.hh"
#include "../../socket/player_socket.hh"

class PlayPacketHandler : public PacketHandler
{
public:
	void handle(PlayerSocket* sock, Packet& packet) override;
	void disconnect(PlayerSocket* sock, ChatComponent* chat) override;

private:
	void handleConfirmTeleport(PlayerSocket* sock, Packet& packet);
	void handleQueryBlockEntityTag(PlayerSocket* sock, Packet& packet);
	void handleChangeDifficulty(PlayerSocket* sock, Packet& packet);
	void handleMessageAck(PlayerSocket* sock, Packet& packet);
	void handleChatCommand(PlayerSocket* sock, Packet& packet);
	void handleChatMessage(PlayerSocket* sock, Packet& packet);
	void handlePlayerSession(PlayerSocket* sock, Packet& packet);
	void handleClientCommand(PlayerSocket* sock, Packet& packet);
	void handleClientInfo(PlayerSocket* sock, Packet& packet);
	void handleCommandSuggestionReq(PlayerSocket* sock, Packet& packet);
	void handleClickContainerButton(PlayerSocket* sock, Packet& packet);
	void handleClickContainer(PlayerSocket* sock, Packet& packet);
	void handleCloseContainer(PlayerSocket* sock, Packet& packet);
	void handlePluginMessage(PlayerSocket* sock, Packet& packet);
	void handleEditBook(PlayerSocket* sock, Packet& packet);
	void handleQueryEntityTag(PlayerSocket* sock, Packet& packet);
	void handleInteract(PlayerSocket* sock, Packet& packet);
	void handleJigsawGenerate(PlayerSocket* sock, Packet& packet);
	void handleKeepAlive(PlayerSocket* sock, Packet& packet);
	void handleLockDifficulty(PlayerSocket* sock, Packet& packet);
	void handleSetPlayerPos(PlayerSocket* sock, Packet& packet);
	void handleSetPlayerPosAndRot(PlayerSocket* sock, Packet& packet);
	void handleSetPlayerRot(PlayerSocket* sock, Packet& packet);
	void handleSetPlayerOnGround(PlayerSocket* sock, Packet& packet);
	void handleMoveVehicle(PlayerSocket* sock, Packet& packet);
	void handlePaddleBoat(PlayerSocket* sock, Packet& packet);
	void handlePickItem(PlayerSocket* sock, Packet& packet);
	void handlePlaceRecipe(PlayerSocket* sock, Packet& packet);
	void handlePlayerAbilities(PlayerSocket* sock, Packet& packet);
	void handlePlayerAction(PlayerSocket* sock, Packet& packet);
	void handlePlayerCommand(PlayerSocket* sock, Packet& packet);
	void handlePlayerInput(PlayerSocket* sock, Packet& packet);
	void handlePong(PlayerSocket* sock, Packet& packet);
	void handleChangeRecipeBookSettings(PlayerSocket* sock, Packet& packet);
	void handleSetSeenRecipe(PlayerSocket* sock, Packet& packet);
	void handleRenameItem(PlayerSocket* sock, Packet& packet);
	void handleResourcePack(PlayerSocket* sock, Packet& packet);
	void handleSeenAdvancements(PlayerSocket* sock, Packet& packet);
	void handleSelectTrade(PlayerSocket* sock, Packet& packet);
	void handleSetBeaconEffect(PlayerSocket* sock, Packet& packet);
	void handleSetHeldItem(PlayerSocket* sock, Packet& packet);
	void handleProgramCommandBlock(PlayerSocket* sock, Packet& packet);
	void handleProgramCommandBlockMinecart(PlayerSocket* sock, Packet& packet);
	void handleSetCreativeModeSlot(PlayerSocket* sock, Packet& packet);
	void handleProgramJigsawBlock(PlayerSocket* sock, Packet& packet);
	void handleProgramStructureBlock(PlayerSocket* sock, Packet& packet);
	void handleUpdateSign(PlayerSocket* sock, Packet& packet);
	void handleSwingArm(PlayerSocket* sock, Packet& packet);
	void handleTeleportToEntity(PlayerSocket* sock, Packet& packet);
	void handleUseItemOn(PlayerSocket* sock, Packet& packet);
	void handleUseItem(PlayerSocket* sock, Packet& packet);
};
