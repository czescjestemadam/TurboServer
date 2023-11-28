#pragma once
#include "packet_handler.hh"
#include "../../socket/player_socket.hh"
#include "server/auth/game_profile.hh"

class LoginPacketHandler : public PacketHandler
{
public:
	explicit LoginPacketHandler(PlayerSocket* sock);

	void handle(Packet& packet) override;
	void disconnect(ChatComponent chat) override;

private:
	void handleLoginStart(Packet& packet);
	void handleEncryptionRes(Packet& packet);
	void handleLoginPluginRes(Packet& packet);

	void setCompression(int threshold);
	void success(GameProfile& profile);

public:
	static bool isNameValid(const std::string& name);
};
