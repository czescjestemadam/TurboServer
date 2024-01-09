#include "server/turbo_server.hh"
#include "server/utils/pid.hh"
#include "server/utils/console/console_handler.hh"

#include <iostream>

#include "server/utils/http/url.hh"
#include "server/utils/http/ssl/ssl.hh"

#include <netdb.h>

int main(int argc, char* argv[])
{
	const int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0)
		return 1;

	const Url url = Url::parse("https://dummyjson.com/products/1");
	hostent* host = gethostbyname2(url.getHostname().c_str(), AF_INET);

	sockaddr_in addr = {
		AF_INET,
		htons(443),
		htonl(0x01010101)
	};
	if (connect(fd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)))
		return 1;

	Ssl ssl;
	ssl.setFd(fd);
	ssl.connect();

	ssl.write(std::format("GET {}\n\r\n\r", url.getPath()));

	char buff[1024] = { 0 };
	ssl.read(buff, sizeof(buff) - 1);
	std::cout << buff << std::endl;

	close(fd);

	// RunArgs args(argc, argv);
	// args.parse();
	//
	// if (args.hasFlag("help"))
	// {
	// 	std::cout << "TurboServer " + TurboServer::getVersion() << "\n\n"
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
	// 	std::cout << "TurboServer " + TurboServer::getVersion() << '\n';
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
