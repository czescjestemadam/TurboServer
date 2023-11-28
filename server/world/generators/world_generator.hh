#pragma once
#include "server/world/chunk.hh"
#include "server/world/block/state/block_state.hh"

class WorldGenerator
{
protected:
	long seed;

public:
	explicit WorldGenerator(long seed);

	virtual Chunk getChunk(int x, int z) = 0;
	virtual BlockState getBlock(int x, int y, int z) = 0;

	long getSeed() const;
};
