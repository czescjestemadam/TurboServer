#include "living_entity.hh"

LivingEntity::LivingEntity(const EntityType& type) : Entity(type)
{
}

void LivingEntity::tick()
{
	Entity::tick();
}
