#include "velocity_config.hh"
#include "json_helper.hh"

void VelocityConfig::load(nlohmann::json&& j)
{
	JSON_HELPER_READ(enabled)
	JSON_HELPER_READ(onlineMode)
	JSON_HELPER_READ(secret)
}

nlohmann::json VelocityConfig::save()
{
	nlohmann::json j;

	JSON_HELPER_WRITE(enabled)
	JSON_HELPER_WRITE(onlineMode)
	JSON_HELPER_WRITE(secret)

	return j;
}

std::string VelocityConfig::getName()
{
	return "velocity";
}
