#pragma once
#include "lib/json.hpp"

class IConfig
{
public:
	virtual void load(nlohmann::json&& j) = 0;
	virtual nlohmann::json save() = 0;

	virtual std::string getName() = 0;
};
