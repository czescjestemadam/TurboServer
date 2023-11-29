#include "turbo_server.hh"

static TurboServer* instance;

TurboServer::TurboServer(Logger&& logger, RunArgs&& args) : logger(logger), args(args)
{
	if (!instance)
		instance = this;

	logger.info("Loading");

	if (!args.hasFlag("default-configs"))
		configManager.init("configs");
}

TurboServer::~TurboServer() = default;


void TurboServer::start()
{
	logger.info("Starting");
	running = true;
	startTime = std::chrono::system_clock::now();

	// world

	// command

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
	logger.info("Stopping");

	ticker.stop();
	networkManager.stop();

	running = false;
	runningConditionVar.notify_all();
}

void TurboServer::tick()
{
	// todo thread pool
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

std::chrono::time_point<std::chrono::system_clock> TurboServer::getStartTime() const
{
	return startTime;
}

std::vector<std::unique_ptr<Entity>>& TurboServer::getEntities()
{
	return entities;
}

Entity* TurboServer::getEntity(int id)
{
	for (std::unique_ptr<Entity>& e : entities)
		if (e->id == id)
			return e.get();

	return nullptr;
}

Entity* TurboServer::getEntity(UUID uuid)
{
	for (std::unique_ptr<Entity>& e : entities)
		if (e->uuid == uuid)
			return e.get();

	return nullptr;
}

void TurboServer::addEntity(std::unique_ptr<Entity>&& entity)
{
	entities.push_back(std::move(entity));
}

std::vector<PlayerEntity*> TurboServer::getPlayers()
{
	std::vector<PlayerEntity*> players;

	for (std::unique_ptr<Entity>& entity : entities)
	{
		auto* player = dynamic_cast<PlayerEntity*>(entity.get());
		if (player)
			players.push_back(player);
	}

	return players;
}

PlayerEntity* TurboServer::getPlayer(UUID uuid)
{
	for (std::unique_ptr<Entity>& e : entities)
		if (e->uuid == uuid)
			return (PlayerEntity*)e.get();

	return nullptr;
}

PlayerEntity* TurboServer::getPlayer(const std::string& name)
{
	for (std::unique_ptr<Entity>& e : entities)
	{
		auto* player = dynamic_cast<PlayerEntity*>(e.get());
		if (player && player->name == name)
			return player;
	}

	return nullptr;
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

const ProtocolVersion& TurboServer::getProtocolVersion()
{
	return ProtocolVersion::v1_20;
}

std::string TurboServer::getVersion()
{
	return "0.1";
}
