#include "plugins_config.hh"

void PluginsConfig::load(nlohmann::json&& j)
{

}

nlohmann::json PluginsConfig::save()
{
	return nlohmann::json();
}

std::string PluginsConfig::getName()
{
	return "plugins";
}
