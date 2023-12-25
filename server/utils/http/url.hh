#pragma once
#include <string>

class Url
{
	std::string protocol;
	std::string hostname;
	int port = -1;
	std::string path;

public:
	Url() = default;
	Url(const std::string& protocol, const std::string& hostname, int port, const std::string& path);

	const std::string& getProtocol() const;
	const std::string& getHostname() const;
	int getPort() const;
	const std::string& getPath() const;

	std::string toString() const;


	static Url&& parse(const std::string& str);
};
