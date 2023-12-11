#pragma once
#include <string>

#include "lib/json.hpp"

class HoverEvent
{
public:
	virtual ~HoverEvent() = default;

	virtual std::string getAction() = 0;
	virtual std::string getContents() = 0;
};
