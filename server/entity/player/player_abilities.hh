#pragma once


class PlayerAbilities
{
public:
	bool invulnerable = false;
	bool flying = false;
	bool mayFly = false;
	bool instabuild = false;
	bool mayBuild = true;
	float flyingSpeed = 0.05f;
	float walkingSpeed = 0.1f;
};
