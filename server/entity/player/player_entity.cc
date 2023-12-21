#include "player_entity.hh"

#include <format>

PlayerEntity::PlayerEntity(PlayerSocket* socket) : LivingEntity({}), socket(socket)
{
}

void PlayerEntity::tick()
{
	LivingEntity::tick();
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
