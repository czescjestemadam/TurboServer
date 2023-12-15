#include "server/turbo_server.hh"
#include "server/utils/PID.hh"
#include "server/utils/console/console_handler.hh"

// #include "server/events/event_listener.hh"
#include "server/events/ievent.hh"

class TestEvent : public IEvent<TestEvent>
{
public:
	std::string str;
};

class TestEventListener : public EventListener<TestEvent>
{
public:
	void onEvent(TestEvent& e) override
	{
		std::cout << "ev str: " << e.str << std::endl;
	}
};

int main(int argc, char* argv[])
{
	TestEventListener listener;



	return 0;

	RunArgs args(argc, argv);
	args.parse();

	if (args.hasFlag("help"))
	{
		std::cout << "TurboServer v" + TurboServer::getVersion() << "\n\n"
				  << "Usage: TurboServer [options]\n\n"
				  << "Options:\n"
				  << " --help                 shows help\n"
				  << " --version --ver        shows TurboServer version\n"
				  << " --default-configs      skips loading/saving configs, using default\n"
				  << " --no-logs              skips logging to file\n";

		return 0;
	}
	else if (args.hasFlag("ver") || args.hasFlag("version"))
	{
		std::cout << "TurboServer v" + TurboServer::getVersion() << '\n';
		return 0;
	}

	if (PID::readFile() > 0)
	{
		std::cout << "TurboServer is already running in this directory\n";
		return 1;
	}

	PID::writeFile();

	ConsoleHandler::init();

	Logger logger("TurboServer");
	logger.info("Parsed " + args.toString());

	TurboServer server(std::move(logger), std::move(args));
	server.start();

	PID::removeFile();

	return 0;
}
