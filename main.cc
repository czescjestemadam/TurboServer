#include "server/turbo_server.hh"
#include "server/utils/console/console_handler.hh"

int main(int argc, char* argv[])
{
	RunArgs args(argc, argv);
	args.parse();

	if (args.hasFlag("help"))
	{
		std::cout << "TurboServer v" + TurboServer::getVersion() << "\n\n"
				  << "Usage: TurboServer [options]\n\n"
				  << "Options:\n"
				  << " --help                 shows help\n"
				  << " --ver                  shows TurboServer version\n"
				  << " --default-configs      skips loading/saving configs, using default\n"
				  << " --no-logs              skips logging to file\n";

		return 0;
	}
	else if (args.hasFlag("ver") || args.hasFlag("version"))
	{
		std::cout << "TurboServer v" + TurboServer::getVersion() << '\n';
		return 0;
	}

	ConsoleHandler::init();

	Logger logger("TurboServer");
	logger.info("Parsed " + args.toString());

	TurboServer server(std::move(logger), std::move(args));
	server.start();

	return 0;
}
