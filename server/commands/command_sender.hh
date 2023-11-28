#pragma once
#include <string>
#include <vector>

class CommandSender
{
public:
	virtual void sendMessage(const std::string& msg) = 0;
	virtual void sendMessage(const std::vector<std::string>& msg) = 0;
};
