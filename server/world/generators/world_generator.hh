#pragma once
#include "server/world/chunk.hh"
#include "server/world/block/state/block_state.hh"
#include "server/world/info/world_type.hh"

class WorldGenerator
{
protected:
	long seed;

public:
	explicit WorldGenerator(long seed);
	virtual ~WorldGenerator() = default;

	virtual Chunk getChunk(int x, int z) = 0;
	virtual BlockState getBlock(int x, int y, int z) = 0;


	static std::unique_ptr<WorldGenerator> forType(WorldType* type, long seed);
};
