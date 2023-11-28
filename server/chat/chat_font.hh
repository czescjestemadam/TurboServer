#pragma once
#include <string>

class ChatFont
{
	int id;
	std::string identifier;

public:
	ChatFont(int id, std::string identifier);

	const std::string& getIdentifier() const;

	bool operator==(const ChatFont& rhs) const;
	bool operator!=(const ChatFont& rhs) const;

	static ChatFont DEFAULT;
	static ChatFont UNICODE;
	static ChatFont ENCHANTING_TABLE;
};
