#include "server/turbo_server.hh"
#include "server/utils/pid.hh"
#include "server/utils/console/console_handler.hh"

#include <iostream>

#include "server/db/db_model.hh"

class TestModel : public DBModel
{
public:
	int id = -1;
	std::string name;
	int score;

	TestModel(const std::string& name, int score) : name(name), score(score)
	{
	}

	data_t serialize() const override
	{
		return {
			{ "id", id },
			{ "name", name },
			{ "score", score }
		};
	}

	void deserialize(data_t& data) override
	{
		id = std::any_cast<int>(data["id"]);
		name = std::any_cast<std::string>(data["name"]);
		score = std::any_cast<int>(data["score"]);
	}
};

int main(int argc, char* argv[])
{
	TestModel model("jajko", 19);


	// RunArgs args(argc, argv);
	// args.parse();
	//
	// if (args.hasFlag("help"))
	// {
	// 	std::cout << "TurboServer v" + TurboServer::getVersion() << "\n\n"
	// 			  << "Usage: TurboServer [options]\n\n"
	// 			  << "Options:\n"
	// 			  << " --help                 shows help\n"
	// 			  << " --version --ver        shows TurboServer version\n"
	// 			  << " --default-configs      skips loading/saving configs, using default\n"
	// 			  << " --no-logs              skips logging to file\n"
	// 			  << " --no-pidfile			  skips writing pidfile\n";
	//
	// 	return 0;
	// }
	// if (args.hasFlag("ver") || args.hasFlag("version"))
	// {
	// 	std::cout << "TurboServer v" + TurboServer::getVersion() << '\n';
	// 	return 0;
	// }
	//
	// if (PID::readFile() > 0)
	// {
	// 	std::cout << "TurboServer is already running in this directory\n";
	// 	return 1;
	// }
	//
	// if (!args.hasFlag("no-pidfile"))
	// 	PID::writeFile();
	//
	// ConsoleHandler::init();
	//
	// Logger logger("TurboServer");
	// logger.info("Parsed " + args.toString());
	//
	// TurboServer server(std::move(logger), std::move(args));
	// server.start();
	//
	// PID::removeFile();

	return 0;
}
