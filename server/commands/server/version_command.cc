#include "version_command.hh"

#include "server/turbo_server.hh"

VersionCommand::VersionCommand() : Command("version", { "ver" }, "turboserver.cmd.version", "", "")
{
}

bool VersionCommand::execute(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args)
{
	sender->sendMessage("TurboServer v" + TurboServer::getVersion());
	return true;
}

std::vector<std::string> VersionCommand::suggest(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args)
{
	return {};
}
