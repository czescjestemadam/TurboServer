#pragma once
#include "../utils/logger/logger.hh"
#include "server_config.hh"
#include "world_config.hh"
#include "network_config.hh"
#include "plugins_config.hh"
#include "permissions_config.hh"
#include "commands_config.hh"
#include "anticheat_config.hh"
#include "velocity_config.hh"

#include <filesystem>
#include <vector>
#include <string>

class ConfigManager
{
	Logger logger{ "ConfigManager" };

	std::filesystem::path configDir;

	std::vector<IConfig*> configs;
	ServerConfig serverConfig;
	WorldConfig worldConfig;
	NetworkConfig networkConfig;
	PluginsConfig pluginsConfig;
	PermissionsConfig permissionsConfig;
	CommandsConfig commandsConfig;
	AnticheatConfig anticheatConfig;
	VelocityConfig velocityConfig;

public:
	void init(const std::string& configDir);

	void load();
	void save();

	ServerConfig& getServerConfig();
	WorldConfig& getWorldConfig();
	NetworkConfig& getNetworkConfig();
	PluginsConfig& getPluginsConfig();
	PermissionsConfig& getPermissionsConfig();
	CommandsConfig& getCommandsConfig();
	AnticheatConfig& getAnticheatConfig();
	VelocityConfig& getVelocityConfig();

private:
	void loadOrGenerate(IConfig* cfg);
	void save(IConfig* cfg, std::string successMessage = "saved");
};
