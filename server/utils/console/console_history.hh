#pragma once
#include <vector>
#include <string>

class ConsoleHistory
{
	std::vector<std::string> lines;
	int cursor = 0;
};
