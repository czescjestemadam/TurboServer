#pragma once
#include "iconfig.hh"

class PermissionsConfig : public IConfig
{
public:
	int opPermissionLevel = 4;
	int functionPermissionLevel = 2;
	std::string noPermissionMessage = "&cI'm sorry, but you do not have permission to perform this command.";

	bool whitelist = false;
	// kicks all not whitelisted users when enabled
	bool enforceWhitelist = false;

	// send console command output to ops
	bool broadcastConsoleToOps = true;

	bool consoleHasAllPermissions = false;


	void load(nlohmann::json&& j) override;
	nlohmann::json save() override;

	std::string getName() override;
};
