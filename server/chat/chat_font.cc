#include <utility>

#include "chat_font.hh"

ChatFont::ChatFont(int id, std::string identifier) : id(id), identifier(std::move(identifier))
{
}

const std::string& ChatFont::getIdentifier() const
{
	return identifier;
}

bool ChatFont::operator==(const ChatFont& rhs) const
{
	return id == rhs.id;
}

bool ChatFont::operator!=(const ChatFont& rhs) const
{
	return !(rhs == *this);
}

ChatFont ChatFont::DEFAULT = { 0, "minecraft:default" };
ChatFont ChatFont::UNICODE = { 1, "minecraft:uniform" };
ChatFont ChatFont::ENCHANTING_TABLE = { 2, "minecraft:alt" };
