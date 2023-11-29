#pragma once
#include "log_level.hh"

#include <iostream>
#include <functional>
#include <format>

class Logger
{
	std::string name;

public:
	explicit Logger(std::string name);

	void log(const LogLevel& level, std::string_view msg);
	void log(const LogLevel& level, const std::function<std::string_view()>& func);

	void mdebug(std::string_view msg);
	void debug(std::string_view msg);
	void info(std::string_view msg);
	void warn(std::string_view msg);
	void error(std::string_view msg);
	void crash(std::string_view msg);

	template<class ...T>
	inline void mdebug(std::format_string<T...> format, T&& ...args);

	template<class ...T>
	inline void debug(std::format_string<T...> format, T&& ...args);

	template<class ...T>
	inline void info(std::format_string<T...> format, T&& ...args);

	template<class ...T>
	inline void warn(std::format_string<T...> format, T&& ...args);

	template<class ...T>
	inline void error(std::format_string<T...> format, T&& ...args);

	template<class ...T>
	inline void crash(std::format_string<T...> format, T&& ...args);

	void stacktrace(const LogLevel& level, std::string_view msg);
	void stacktrace(const LogLevel& level, const std::function<std::string_view()>& func);

	template<class ...T>
	inline void stacktrace(const LogLevel& level, std::format_string<T...> format, T&& ...args);

	const std::string& getName() const;
	void setName(std::string name);

private:
	static std::string getTime();
};

#include "logger_va.ii"
