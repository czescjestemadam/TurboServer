#include "str_utils.hh"

#include <algorithm>

std::vector<std::string> StrUtils::split(const std::string& str, char del)
{
	std::vector<std::string> ret;
	std::string buff;

	for (char c : str)
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
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](char c)
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
