#pragma once

#include <string>

class WorldType
{
	int id;

public:
	std::string name;


	WorldType(int id, std::string name);


	static WorldType OVERWORLD;
	static WorldType NETHER;
	static WorldType THE_END;
};
