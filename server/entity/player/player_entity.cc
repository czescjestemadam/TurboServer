#include "player_entity.hh"

PlayerEntity::PlayerEntity(PlayerSocket* socket) : LivingEntity({}), socket(socket)
{
}

void PlayerEntity::setGameMode(GameMode* mode)
{
	previousGameMode = gameMode;
	gameMode = mode;
}


std::string PlayerEntity::toString() const
{
	return std::format("PlayerEntity[id={}, name={}, addr={}]", id, name, socket->getAddress());
}
