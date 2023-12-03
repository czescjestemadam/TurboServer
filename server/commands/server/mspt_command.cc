#include "mspt_command.hh"

#include "server/turbo_server.hh"

MsptCommand::MsptCommand() : Command("mspt", "turboserver.cmd.mspt")
{
}

bool MsptCommand::execute(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args)
{
	TickTimes& times = TurboServer::get()->getTicker().getTimes();
	sender->sendMessage({
			"MSPT min/max/avg: 10s, 30s, 1min, 5min",
			std::format("{}, {}, {}, {}", times.toString(200), times.toString(600), times.toString(1200), times.toString(6000))
	});

	return true;
}

std::vector<std::string> MsptCommand::suggest(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args)
{
	return {};
}
