#include "placeholder_manager.hh"

#include "players/playercount_placeholder.hh"

void PlaceholderManager::registerDefaultPlaceholders()
{
	registerPlaceholder(std::make_unique<PlayercountPlaceholder>());
}

void PlaceholderManager::registerPlaceholder(std::unique_ptr<IPlaceholder>&& placeholder)
{
	placeholders[placeholder->getName()] = std::move(placeholder);
}

void PlaceholderManager::replaceString(PlayerEntity* player, std::string& str)
{
	size_t pos = 0;
	while (pos != std::string::npos)
	{
		pos = str.find('{', pos);
		if (pos == std::string::npos)
			break;

		const size_t endPos = str.find('}', pos);
		if (endPos == std::string::npos)
			break;

		const std::string name = str.substr(pos + 1, endPos - pos - 1);
		if (placeholders.contains(name))
		{
			const std::unique_ptr<IPlaceholder>& placeholder = placeholders[name];
			str.replace(pos, endPos - pos + 1, placeholder->getReplacementFor(player));
		}

		pos = endPos + 1;
	}
}

std::string PlaceholderManager::replaceString(PlayerEntity* player, std::string&& str)
{
	replaceString(player, str);
	return str;
}


std::string PlaceholderManager::replaceStringCp(PlayerEntity* player, const std::string& str)
{
	std::string s = str;
	replaceString(player, s);
	return s;
}
