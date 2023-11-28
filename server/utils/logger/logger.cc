#include "logger.hh"

#include "server/utils/console/console_handler.hh"

#include <iostream>
#include <utility>
#include <chrono>

Logger::Logger(std::string name) : name(std::move(name))
{
}

void Logger::log(const LogLevel& level, std::string_view msg)
{
	std::string str = std::format("[{}] [{}/{}]: {}", getTime(), name, level.getName(), msg);

	if (level >= LogLevel::ERROR)
		ConsoleHandler::err(str);
	else
		ConsoleHandler::log(str);
}

void Logger::log(const LogLevel& level, const std::function<std::string_view()>& func)
{
	log(level, func());
}

void Logger::mdebug(std::string_view msg)
{
	log(LogLevel::MDEBUG, msg);
}

void Logger::debug(std::string_view msg)
{
	log(LogLevel::DEBUG, msg);
}

void Logger::info(std::string_view msg)
{
	log(LogLevel::INFO, msg);
}

void Logger::warn(std::string_view msg)
{
	log(LogLevel::WARN, msg);
}

void Logger::error(std::string_view msg)
{
	log(LogLevel::ERROR, msg);
}

void Logger::crash(std::string_view msg)
{
	log(LogLevel::CRASH, msg);
}

const std::string& Logger::getName() const
{
	return name;
}

void Logger::setName(std::string name)
{
	this->name = std::move(name);
}


std::string Logger::getTime()
{
	return std::format("{:%T}", std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()));
}
