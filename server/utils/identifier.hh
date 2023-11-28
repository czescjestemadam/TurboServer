#pragma once
#include <string>

class Identifier
{
	std::string space;
	std::string key;

public:
	Identifier(const std::string& str);
	Identifier(std::string space, std::string key);

	const std::string& getSpace() const;
	const std::string& getKey() const;

	std::string toString() const;

	static Identifier mc(const std::string& key);
	static Identifier ts(const std::string& key);

	static Identifier nil();
};
