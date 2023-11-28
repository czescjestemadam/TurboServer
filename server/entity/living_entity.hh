#pragma once
#include "entity.hh"
#include "hand.hh"

class LivingEntity : public Entity
{
public:
	float health;
	float absorptionAmount;

	bool swinging;
	Hand swingHand;
	int swingTime;

	int hurtTime;
	int hurtDuration;
	float lastHurt;
	int deathTime;

	bool jumping;

	LivingEntity* lastHurtByMob;
	ulong lastHurtByMobTimestamp;
	LivingEntity* lastHurtMob;
	ulong lastHurtMobTimestamp;
	// DamageSource lastDamageSource;
	ulong lastDamageTimestamp;

	float speed;
	int noJumpDelay;

	// ItemStack useItem;
	int useItemRemaining;


	explicit LivingEntity(const EntityType& type);
};
