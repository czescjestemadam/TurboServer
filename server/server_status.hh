#pragma once
#include "utils/png.hh"

class ServerStatus
{
	Png icon;
	std::string json;
public:

	void loadIcon();
	void update();

	const std::string& getJson() const;
};
