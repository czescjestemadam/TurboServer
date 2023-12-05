#include "bounding_box.hh"

#include <algorithm>

BoundingBox::BoundingBox(const Vec3d& min, const Vec3d& max) : min(min), max(max)
{
}

BoundingBox::BoundingBox(double minX, double minY, double minZ, double maxX, double maxY, double maxZ) :
		min(minX, minY, minZ), max(maxX, maxY, maxZ)
{
}

void BoundingBox::normalize()
{
	Vec3d oMin = min;
	Vec3d oMax = max;

	min = { std::min(oMin.x, oMax.x), std::min(oMin.y, oMax.y), std::min(oMin.z, oMax.z) };
	max = { std::max(oMin.x, oMax.x), std::max(oMin.y, oMax.y), std::max(oMin.z, oMax.z) };
}

bool BoundingBox::isInside(const Vec3d& vec) const
{
	return (min.x < vec.x && min.y < vec.y && min.z < vec.z) && (vec.x < max.x && vec.y < max.y && vec.z < max.z);
}

bool BoundingBox::collides(const BoundingBox& box) const
{
	return isInside(box.min) || isInside(box.max) || box.isInside(min) || box.isInside(max);
}
