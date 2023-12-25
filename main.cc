#include "server/turbo_server.hh"
#include "server/utils/pid.hh"
#include "server/utils/console/console_handler.hh"

#include <iostream>

#include <openssl/ssl.h>

int main(int argc, char* argv[])
{
	const int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0)
		return 1;

	sockaddr_in addr = {
		AF_INET,
		htons(443),
		htonl(0x01010101)
	};
	if (connect(fd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)))
		return 1;

	SSL_CTX* ctx = SSL_CTX_new(TLS_method());
	SSL* ssl = SSL_new(ctx);
	SSL_set_fd(ssl, fd);
	SSL_connect(ssl);
	const std::string req = "GET /\n\r\n\r";
	SSL_write(ssl, req.c_str(), static_cast<int>(req.length()));

	char buff[1024] = { 0 };
	SSL_read(ssl, buff, sizeof(buff) - 1);

	std::cout << buff << std::endl;

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
