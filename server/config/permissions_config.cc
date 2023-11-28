#include "permissions_config.hh"

#include "json_helper.hh"

void PermissionsConfig::load(nlohmann::json&& j)
{
	JSON_HELPER_READ(opPermissionLevel)
	JSON_HELPER_READ(functionPermissionLevel)
	JSON_HELPER_READ(noPermissionMessage)

	JSON_HELPER_READ(whitelist)
	JSON_HELPER_READ(enforceWhitelist)

	JSON_HELPER_READ(broadcastConsoleToOps)

	JSON_HELPER_READ(consoleHasAllPermissions)
}

nlohmann::json PermissionsConfig::save()
{
	nlohmann::json j;

	JSON_HELPER_WRITE(opPermissionLevel)
	JSON_HELPER_WRITE(functionPermissionLevel)
	JSON_HELPER_WRITE(noPermissionMessage)

	JSON_HELPER_WRITE(whitelist)
	JSON_HELPER_WRITE(enforceWhitelist)

	JSON_HELPER_WRITE(broadcastConsoleToOps)

	JSON_HELPER_WRITE(consoleHasAllPermissions)

	return j;
}

std::string PermissionsConfig::getName()
{
	return "permissions";
}
