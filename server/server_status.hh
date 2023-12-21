#pragma once
#include "utils/png.hh"

class ServerStatus
{
public:
	Png icon;
	std::string json;

	void loadIcon();
	void update();

	const std::string& getJson() const;
};
