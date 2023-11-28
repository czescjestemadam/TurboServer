#include "chunk.hh"

Chunk::Chunk(int x, int z) : x(x), z(z)
{
}

int Chunk::getX() const
{
	return x;
}

int Chunk::getZ() const
{
	return z;
}
