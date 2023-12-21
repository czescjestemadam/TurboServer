#pragma once
#include <vector>
#include <filesystem>

typedef unsigned char byte_t;

class Png
{
public:
	std::vector<byte_t> bytes;
	uint width = 0;
	uint height = 0;

	void load(const std::filesystem::path& file);

	bool isValid() const;
};
