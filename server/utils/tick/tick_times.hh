#pragma once
#include <list>
#include <string>

class TickTimes
{
	int ticksLimit;
	std::list<float> times;

public:
	explicit TickTimes(int ticksLimit);

	void add(float time);

	ulong getSize() const;

	float getMin(int num) const;
	float getMax(int num) const;
	float getAvg(int num) const;

	// min/max/avg
	std::string toString(int num) const;

	// min/max/avg
	std::string toTpsString(int num) const;
};
