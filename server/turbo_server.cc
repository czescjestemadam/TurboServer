#include "turbo_server.hh"
#include "utils/console/console_handler.hh"

static TurboServer* instance;

TurboServer::TurboServer(Logger&& logger, RunArgs&& args) : logger(logger), args(args)
{
	if (!instance)
		instance = this;

	logger.info("Loading");

	if (!args.hasFlag("default-configs"))
		configManager.init("configs");
}


void TurboServer::start()
{
	logger.info("Starting");
	running = true;
	startTime = std::chrono::system_clock::now();

	// world

	commandManager.registerCommands();

	NetworkConfig& net = configManager.getNetworkConfig();
	networkManager.start(net.serverIp, net.serverPort);

	// plugin

	ticker.start();

	std::unique_lock lock(runningMutex);
	while (running)
		runningConditionVar.wait(lock);
}

void TurboServer::stop()
{
	if (!running)
		return;

	logger.info("Stopping");

	ticker.stop();
	networkManager.stop();

	running = false;
	runningConditionVar.notify_all();
}

void TurboServer::tick()
{
	playerList.tick();

	worldManager.tick();
	networkManager.tick();

	scheduler.tick();
}


const RunArgs& TurboServer::getRunArgs()
{
	return args;
}

bool TurboServer::isRunning() const
{
	return running;
}

std::chrono::system_clock::time_point TurboServer::getStartTime() const
{
	return startTime;
}

PlayerList& TurboServer::getPlayerList()
{
	return playerList;
}


ConfigManager& TurboServer::getConfigManager()
{
	return configManager;
}

WorldManager& TurboServer::getWorldManager()
{
	return worldManager;
}

CommandManager& TurboServer::getCommandManager()
{
	return commandManager;
}

NetworkManager& TurboServer::getNetworkManager()
{
	return networkManager;
}

PermissionManager& TurboServer::getPermissionManager()
{
	return permissionManager;
}

BanManager& TurboServer::getBanManager()
{
	return banManager;
}

PluginManager& TurboServer::getPluginManager()
{
	return pluginManager;
}

Ticker& TurboServer::getTicker()
{
	return ticker;
}

TurboScheduler& TurboServer::getScheduler()
{
	return scheduler;
}


TurboServer* TurboServer::get()
{
	return instance;
}

CommandSender* TurboServer::getConsoleSender()
{
	return &ConsoleHandler::terminalConsole;
}

const ProtocolVersion& TurboServer::getProtocolVersion()
{
	return ProtocolVersion::v1_20;
}

std::string TurboServer::getVersion()
{
	return "0.1";
}
