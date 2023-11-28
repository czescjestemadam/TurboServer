#pragma once
#include "block/block.hh"

class Chunk
{
	int x;
	int z;


public:
	Chunk(int x, int z);

	int getX() const;
	int getZ() const;
};
