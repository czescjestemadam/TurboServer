#include "entity.hh"

static uint idCounter = 0;

Entity::Entity(const EntityType& type) : type(type), id(idCounter++), uuid(UUID::random())
{
}

Entity::Entity(const EntityType& type, uint id, const UUID& uuid) : type(type), id(id), uuid(uuid)
{
}


void Entity::tick()
{
	++age;
}


