#include "uptime_command.hh"

#include "server/turbo_server.hh"
#include "server/utils/str_utils.hh"

UptimeCommand::UptimeCommand() : Command("uptime", "turboserver.cmd.uptime")
{
}

bool UptimeCommand::execute(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args)
{
	auto time = std::chrono::system_clock::now() - TurboServer::get()->getStartTime();
	sender->sendMessage("Uptime: " + StrUtils::formatUptime(time));
	return true;
}

std::vector<std::string> UptimeCommand::suggest(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args)
{
	return {};
}
