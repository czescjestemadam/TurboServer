#include "tps_command.hh"

#include "server/turbo_server.hh"

TpsCommand::TpsCommand() : Command("tps", "turboserver.cmd.tps")
{
}

bool TpsCommand::execute(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args)
{
	TickTimes& times = TurboServer::get()->getTicker().getTimes();
	sender->sendMessage({
			"TPS min/max/avg: 1min, 5min, 15min",
			std::format("{}, {}, {}", times.toTpsString(1200), times.toTpsString(6000), times.toTpsString(18000))
	});

	return true;
}

std::vector<std::string> TpsCommand::suggest(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args)
{
	return {};
}
