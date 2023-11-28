#pragma once
#include "entity_type.hh"
#include "../utils/uuid.hh"
#include "../utils/vec.hh"
#include "server/world/world.hh"

class Entity
{
public:
	EntityType type;

	uint id = -1;
	UUID uuid;

	bool invulnerable;

	int age;
	int invulnerableTime;
	int portalCooldown;
	int portalTime;

	World* world;
	Vec3d pos;
	Vec3d posOld;
	float eyeHeight;
	bool onGround;
	bool isInPowderSnow;
	bool wasInPowderSnow;
	Vec3d velocity;

	bool wasOnFire;
	bool hasVisualFire;

	explicit Entity(const EntityType& type);
	explicit Entity(const EntityType& type, uint id, const UUID& uuid);


	virtual void tick();

//	virtual void damage(/*source,*/ float amount);
//	virtual void kill();
//
//	virtual void remove();
};
