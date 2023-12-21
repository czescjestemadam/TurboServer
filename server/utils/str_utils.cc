#include "str_utils.hh"

#include <algorithm>

std::vector<std::string> StrUtils::split(const std::string& str, char del)
{
	std::vector<std::string> ret;
	std::string buff;

	for (const char c : str)
	{
		if (c == del)
		{
			if (buff.empty())
				continue;
			ret.push_back(std::move(buff));
			buff = "";
		}
		else
		{
			buff += c;
		}
	}
	if (!buff.empty())
		ret.push_back(std::move(buff));

	return ret;
}

std::string StrUtils::trimc(std::string str)
{
	trim(str);
	return str;
}

std::string StrUtils::trim(std::string& str)
{
	// ltrim
	str.erase(str.begin(), std::ranges::find_if(str, [](char c)
	                                            { return !std::isspace(c); }));

	// rtrim
	str.erase(std::find_if(str.rbegin(), str.rend(), [](char c)
	{ return !std::isspace(c); }).base(), str.end());

	return str;
}

std::string StrUtils::join(const std::vector<std::string>& strings, const std::string& delim)
{
	if (strings.empty())
		return "";

	std::string str = strings.front();

	for (auto it = ++strings.begin(); it != strings.end();)
		str += delim + *it++;

	return str;
}

std::string StrUtils::formatUptime(const std::chrono::system_clock::duration& duration)
{
	std::string str;

	const ulong seconds = std::chrono::duration_cast<std::chrono::seconds>(duration).count();
	uint s = seconds % 60;

	const ulong minutes = seconds / 60;
	uint m = minutes % 60;

	const ulong hours = minutes / 60;
	uint h = hours % 24;

	ulong days = hours / 24;

	return std::format("{} days {:02}:{:02}:{:02}", days, h, m, s);
}
