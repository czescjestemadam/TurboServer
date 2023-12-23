#pragma once
#include <memory>
#include <unordered_map>

#include "iplaceholder.hh"

class PlayerEntity;

class PlaceholderManager
{
	std::unordered_map<std::string, std::unique_ptr<IPlaceholder>> placeholders;

public:
	void registerDefaultPlaceholders();

	void registerPlaceholder(std::unique_ptr<IPlaceholder>&& placeholder);


	void replaceString(PlayerEntity* player, std::string& str);
	std::string replaceString(PlayerEntity* player, std::string&& str);

	std::string replaceStringCp(PlayerEntity* player, const std::string& str);
};
