#include "config_manager.hh"

#include <filesystem>
#include <fstream>

static constexpr int JSON_WRITE_INDENT = 2;

void ConfigManager::init(const std::string& configDir)
{
	logger.info("Loading configs from {}", configDir);

	this->configDir = std::filesystem::current_path() / configDir;
	std::filesystem::create_directory(this->configDir);

	configs.push_back(&serverConfig);
	configs.push_back(&worldConfig);
	configs.push_back(&networkConfig);
	configs.push_back(&pluginsConfig);
	configs.push_back(&permissionsConfig);
	configs.push_back(&commandsConfig);
	configs.push_back(&anticheatConfig);

	load();
}


void ConfigManager::load()
{
	for (IConfig* cfg : configs)
		loadOrGenerate(cfg);
}

void ConfigManager::save()
{
	for (IConfig* cfg : configs)
		save(cfg);
}


ServerConfig& ConfigManager::getServerConfig()
{
	return serverConfig;
}

WorldConfig& ConfigManager::getWorldConfig()
{
	return worldConfig;
}

NetworkConfig& ConfigManager::getNetworkConfig()
{
	return networkConfig;
}

PluginsConfig& ConfigManager::getPluginsConfig()
{
	return pluginsConfig;
}

PermissionsConfig& ConfigManager::getPermissionsConfig()
{
	return permissionsConfig;
}

CommandsConfig& ConfigManager::getCommandsConfig()
{
	return commandsConfig;
}

AnticheatConfig& ConfigManager::getAnticheatConfig()
{
	return anticheatConfig;
}

VelocityConfig& ConfigManager::getVelocityConfig()
{
	return velocityConfig;
}


void ConfigManager::loadOrGenerate(IConfig* cfg)
{
	std::string filename = cfg->getName() + ".json";
	std::filesystem::path file = configDir / filename;

	if (!std::filesystem::exists(file))
	{
		save(cfg, "generated new");
		return;
	}

	std::ifstream ifs(file);
	if (!ifs.good())
	{
		logger.error("failed opening file {}", filename);
		ifs.close();
		return;
	}

	std::string buff;
	std::string line;
	while (std::getline(ifs, line))
		buff += line;

	ifs.close();

	try
	{
		cfg->load(nlohmann::json::parse(buff));
		logger.info("loaded {}", filename);
	}
	catch (const std::exception& e)
	{
		logger.error("failed loading {}: {}", filename, e.what());
	}
}

void ConfigManager::save(IConfig* cfg, std::string successMessage)
{
	std::string filename = cfg->getName() + ".json";
	std::filesystem::path file = configDir / filename;

	std::ofstream ofs(file);
	if (!ofs.good())
	{
		logger.error("failed opening file {}", filename);
		ofs.close();
		return;
	}

	try
	{
		ofs << cfg->save().dump(JSON_WRITE_INDENT);
		logger.info("{} {}", successMessage, filename);
	}
	catch (std::exception& e)
	{
		logger.error("failed saving {}: ", filename, e.what());
	}

	ofs.close();
}
