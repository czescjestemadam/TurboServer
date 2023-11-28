#pragma once
#include <unordered_map>
#include <string>
#include <any>

class ISerializable
{
public:
	virtual std::unordered_map<std::string, std::any> serialize() = 0;
	virtual void deserialize(std::unordered_map<std::string, std::any> values) = 0;
};
