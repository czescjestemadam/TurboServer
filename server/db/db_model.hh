#pragma once
#include <any>
#include <string>
#include <unordered_map>

class DBModel
{
public:
	virtual ~DBModel() = default;

	using data_t = std::unordered_map<std::string, std::any>;

	virtual data_t serialize() const = 0;
	virtual void deserialize(data_t& data) = 0;
};
