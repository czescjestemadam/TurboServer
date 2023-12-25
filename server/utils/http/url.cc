#include "url.hh"

#include <format>

Url::Url(const std::string& protocol, const std::string& hostname, int port, const std::string& path) : protocol(protocol), hostname(hostname), port(port), path(path)
{
}

const std::string& Url::getProtocol() const
{
	return protocol;
}

const std::string& Url::getHostname() const
{
	return hostname;
}

int Url::getPort() const
{
	return port;
}

const std::string& Url::getPath() const
{
	return path;
}


std::string Url::toString() const
{
	return std::format("{}://{}{}{}", protocol, hostname, port > 0 ? ":" + std::to_string(port) : "", path);
}


Url&& Url::parse(const std::string& str)
{
	Url url;

	// todo parse

	return std::move(url);
}
