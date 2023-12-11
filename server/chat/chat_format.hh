#pragma once
#include <string>

class ChatFormat
{
public:
	int id;
	char code;
	std::string name;
	bool isFormat;
	int color;
	int ansiCode;


	ChatFormat(int id, char code, std::string name, int color, int ansiCode);
	ChatFormat(int id, char code, std::string name, int ansiCode);

	bool ansiResetPrefix() const;

	std::string getName() const;
	std::string toString() const;


	std::string operator+(const std::string& str) const;
	bool operator==(const ChatFormat& rhs) const;
	bool operator!=(const ChatFormat& rhs) const;


	static const ChatFormat* fromCode(char c);
	static const ChatFormat* fromName(const std::string& name);


	static ChatFormat BLACK;
	static ChatFormat DARK_BLUE;
	static ChatFormat DARK_GREEN;
	static ChatFormat DARK_AQUA;
	static ChatFormat DARK_RED;
	static ChatFormat DARK_PURPLE;
	static ChatFormat GOLD;
	static ChatFormat GRAY;
	static ChatFormat DARK_GRAY;
	static ChatFormat BLUE;

	static ChatFormat GREEN;
	static ChatFormat AQUA;
	static ChatFormat RED;
	static ChatFormat LIGHT_PURPLE;
	static ChatFormat YELLOW;
	static ChatFormat WHITE;

	static ChatFormat OBFUSCATED;
	static ChatFormat BOLD;
	static ChatFormat STRIKETHROUGH;
	static ChatFormat UNDERLINE;
	static ChatFormat ITALIC;
	static ChatFormat RESET;
};
