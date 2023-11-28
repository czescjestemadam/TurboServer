#include "bounding_box.hh"

BoundingBox::BoundingBox(const Vec3d& min, const Vec3d& max) : min(min), max(max)
{
}

BoundingBox::BoundingBox(double minX, double minY, double minZ, double maxX, double maxY, double maxZ) :
		min(minX, minY, minZ), max(maxX, maxY, maxZ)
{
}
