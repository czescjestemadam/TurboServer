#pragma once
#include "vec.hh"

class BoundingBox
{
public:
	Vec3d min;
	Vec3d max;


	BoundingBox(const Vec3d& min, const Vec3d& max);
	BoundingBox(double minX, double minY, double minZ, double maxX, double maxY, double maxZ);
};
