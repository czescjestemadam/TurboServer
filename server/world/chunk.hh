#pragma once
#include "block/block.hh"

#include <memory>
#include <vector>

class Chunk
{
public:
	int x;
	int z;

	bool isChanged = false;

	std::vector<std::unique_ptr<Block>> blocks;


	Chunk(int x, int z);

	void tick();
};
