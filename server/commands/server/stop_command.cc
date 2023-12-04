#include "stop_command.hh"

#include "server/turbo_server.hh"

StopCommand::StopCommand() : Command("stop", "turboserver.cmd.stop")
{
}

bool StopCommand::execute(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args)
{
	if (TurboServer::getConsoleSender() != sender)
		sender->sendMessage(ChatFormat::RED + "Stopping");
	TurboServer::get()->stop();
	return true;
}

std::vector<std::string> StopCommand::suggest(CommandSender* sender, const std::string& alias, const std::vector<std::string>& args)
{
	return {};
}
