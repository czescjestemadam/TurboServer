#pragma once
#include <string>

#include "lib/json.hpp"

class HoverEvent
{
public:
	virtual ~HoverEvent() = default;

	virtual std::string getAction() = 0;

	// return inner element
	virtual nlohmann::json serializeContents() = 0;
};
