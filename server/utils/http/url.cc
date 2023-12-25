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

bool Url::isValid() const
{
	return !protocol.empty() && !hostname.empty();
}

std::string Url::toString() const
{
	return std::format("{}://{}{}{}", protocol, hostname, port > 0 ? ":" + std::to_string(port) : "", path);
}


Url Url::parse(const std::string& str)
{
	Url url;

	size_t start = 0;
	size_t end = str.find(':');
	url.protocol = str.substr(start, end);

	if (end == std::string::npos)
		return url;

	start = end + 3;
	end = str.find('/', start);
	const std::string host = str.substr(start, end - start);
	const size_t portColon = host.rfind(':');
	if (portColon == std::string::npos)
	{
		url.hostname = host;
	}
	else
	{
		url.hostname = host.substr(0, portColon);
		url.port = std::atoi(host.substr(portColon + 1).c_str());
	}

	if (end == std::string::npos)
		return url;

	url.path = str.substr(end);

	return url;
}
