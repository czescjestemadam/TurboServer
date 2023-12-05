#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <format>
#include <chrono>

namespace StrUtils
{
	std::vector<std::string> split(const std::string& str, char del = ' ');

	std::string trimc(std::string str);
	std::string trim(std::string& str);

	std::string join(const std::vector<std::string>& strings, const std::string& delim);

	template<class T>
	std::string vectorToString(const std::vector<T>& vector)
	{
		if (vector.empty())
			return "[]";

		std::string str = std::format("{}", vector.front());

		for (auto it = ++vector.begin(); it != vector.end();)
			str += ", " + std::format("{}", *it++);

		return '[' + str + ']';
	}

	template<class K, class V>
	std::string mapToString(const std::unordered_map<K, V>& map)
	{
		std::vector<std::string> strs;

		for (auto& [ key, val ] : map)
			strs.push_back(std::format("{{{}={}}}", key, val));

		return '[' + join(strs, ", ") + ']';
	}

	std::string formatUptime(const std::chrono::system_clock::duration& duration);
}
