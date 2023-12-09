#pragma once
#include "iconfig.hh"

class VelocityConfig : public IConfig
{
public:
	bool enabled = false;
	bool onlineMode = true;
	std::string secret;


	void load(nlohmann::json&& j) override;
	nlohmann::json save() override;

	std::string getName() override;
};
