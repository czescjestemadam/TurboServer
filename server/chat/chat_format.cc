#include "chat_format.hh"

#include <vector>

static std::vector<ChatFormat*> formats;

ChatFormat::ChatFormat(int id, char code, std::string name, int color, int ansiCode) :
		id(id), code(code), name(std::move(name)), isFormat(false), color(color), ansiCode(ansiCode)
{
	formats.push_back(this);
}

ChatFormat::ChatFormat(int id, char code, std::string name, int ansiCode) :
		id(id), code(code), name(std::move(name)), isFormat(true), color(0), ansiCode(ansiCode)
{
	formats.push_back(this);
}

bool ChatFormat::ansiResetPrefix() const
{
	return !isFormat;
}

std::string ChatFormat::getName() const
{
	return name;
}

std::string ChatFormat::toString() const
{
	static std::string PREFIX = "§";
	return PREFIX + code;
}


std::string ChatFormat::operator+(const std::string& str) const
{
	return toString() + str;
}

bool ChatFormat::operator==(const ChatFormat& rhs) const
{
	return id == rhs.id;
}

bool ChatFormat::operator!=(const ChatFormat& rhs) const
{
	return !(rhs == *this);
}


const ChatFormat* ChatFormat::fromCode(char c)
{
	for (ChatFormat* format: formats)
		if (format->code == c)
			return format;

	return nullptr;
}

const ChatFormat* ChatFormat::fromName(const std::string& name)
{
	for (ChatFormat* format: formats)
		if (format->name == name)
			return format;

	return nullptr;
}


ChatFormat ChatFormat::BLACK = { 0, '0', "black", 0, 30 };
ChatFormat ChatFormat::DARK_BLUE = { 1, '1', "dark_blue", 170, 34 };
ChatFormat ChatFormat::DARK_GREEN = { 2, '2', "dark_green", 43520, 32 };
ChatFormat ChatFormat::DARK_AQUA = { 3, '3', "dark_aqua", 43690, 36 };
ChatFormat ChatFormat::DARK_RED = { 4, '4', "dark_red", 11141120, 31 };
ChatFormat ChatFormat::DARK_PURPLE = { 5, '5', "dark_purple", 11141290, 35 };
ChatFormat ChatFormat::GOLD = { 6, '6', "gold", 16755200, 33 };
ChatFormat ChatFormat::GRAY = { 7, '7', "gray", 11184810, 37 };
ChatFormat ChatFormat::DARK_GRAY = { 8, '8', "dark_gray", 5592405, 90 };
ChatFormat ChatFormat::BLUE = { 9, '9', "blue", 5592575, 96 };

ChatFormat ChatFormat::GREEN = { 10, 'a', "green", 5635925, 92 };
ChatFormat ChatFormat::AQUA = { 11, 'b', "aqua", 5636095, 96 };
ChatFormat ChatFormat::RED = { 12, 'c', "red", 16733525, 91 };
ChatFormat ChatFormat::LIGHT_PURPLE = { 13, 'd', "light_purple", 16733695, 95 };
ChatFormat ChatFormat::YELLOW = { 14, 'e', "yellow", 16777045, 93 };
ChatFormat ChatFormat::WHITE = { 15, 'f', "white", 16777215, 97 };

ChatFormat ChatFormat::OBFUSCATED = { 16, 'k', "obfuscated", 5 };
ChatFormat ChatFormat::BOLD = { 17, 'l', "bold", 1 };
ChatFormat ChatFormat::STRIKETHROUGH = { 18, 'm', "strikethrough", 9 };
ChatFormat ChatFormat::UNDERLINE = { 19, 'n', "underline", 4 };
ChatFormat ChatFormat::ITALIC = { 20, 'o', "italic", 3 };
ChatFormat ChatFormat::RESET = { -1, 'r', "reset", 0 };
