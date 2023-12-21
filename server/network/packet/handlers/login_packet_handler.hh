#pragma once
#include "packet_handler.hh"
#include "../../socket/player_socket.hh"
#include "server/auth/game_profile.hh"

class LoginPacketHandler : public PacketHandler
{
public:
	void handle(PlayerSocket* sock, Packet& packet) override;
	void disconnect(PlayerSocket* sock, ChatComponent* chat) override;

private:
	void handleLoginStart(PlayerSocket* sock, Packet& packet);
	void handleEncryptionRes(PlayerSocket* sock, Packet& packet);
	void handleLoginPluginRes(PlayerSocket* sock, Packet& packet);

	void setCompression(PlayerSocket* sock, int threshold);
	void success(PlayerSocket* sock, GameProfile& profile);

public:
	static bool isNameValid(const std::string& name);
};
