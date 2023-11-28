#pragma once
#include "iconfig.hh"

class PluginsConfig : public IConfig
{
public:


	void load(nlohmann::json&& j) override;
	nlohmann::json save() override;

	std::string getName() override;
};
