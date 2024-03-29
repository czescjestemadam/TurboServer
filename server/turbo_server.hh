#pragma once
#include "utils/logger/logger.hh"
#include "run_args.hh"
#include "server_status.hh"
#include "config/config_manager.hh"
#include "world/world_manager.hh"
#include "network/network_manager.hh"
#include "plugin/plugin_manager.hh"
#include "entity/player/player_list.hh"
#include "utils/scheduler/turbo_scheduler.hh"
#include "commands/command_manager.hh"
#include "server/network/protocol_version.hh"
#include "server/utils/tick/ticker.hh"
#include "server/permissions/permission_manager.hh"
#include "server/bans/ban_manager.hh"

#include <mutex>
#include <condition_variable>

class TurboServer
{
	Logger logger;
	RunArgs args;

	bool running = false;
	std::mutex runningMutex;
	std::condition_variable runningConditionVar;
	std::chrono::time_point<std::chrono::system_clock> startTime;

	ServerStatus status;

	PlayerList playerList;

	ConfigManager configManager;
	WorldManager worldManager;
	CommandManager commandManager;
	NetworkManager networkManager;
	PermissionManager permissionManager;
	BanManager banManager;
	PluginManager pluginManager;

	Ticker ticker{ std::bind(&TurboServer::tick, this) };
	TurboScheduler scheduler;


public:
	TurboServer(Logger&& logger, RunArgs&& args);
	TurboServer(const TurboServer&) = delete;
	TurboServer(TurboServer&&) = delete;

	void start();
	void stop();

	void tick();


	const RunArgs& getRunArgs();

	bool isRunning() const;
	std::chrono::system_clock::time_point getStartTime() const;

	ServerStatus& getStatus();

	PlayerList& getPlayerList();

	ConfigManager& getConfigManager();
	WorldManager& getWorldManager();
	CommandManager& getCommandManager();
	NetworkManager& getNetworkManager();
	PermissionManager& getPermissionManager();
	BanManager& getBanManager();
	PluginManager& getPluginManager();

	Ticker& getTicker();
	TurboScheduler& getScheduler();


	static TurboServer* get();

	static CommandSender* getConsoleSender();

	static const ProtocolVersion& getProtocolVersion();

	static std::string getVersion();
};
