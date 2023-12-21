#include "tick_times.hh"

#include <format>

TickTimes::TickTimes(int ticksLimit) : ticksLimit(ticksLimit)
{
}

void TickTimes::add(float time)
{
	if (getSize() >= ticksLimit)
		times.pop_back();

	times.push_front(time);
}

ulong TickTimes::getSize() const
{
	return std::distance(times.begin(), times.end());
}

float TickTimes::getMin(int num) const
{
	float min = times.front();

	for (auto it = times.begin(); it != times.end();)
	{
		if (min > *it)
			min = *it;
		++it;

		if (num-- < 0)
			break;
	}

	return min;
}

float TickTimes::getMax(int num) const
{
	float max = times.front();

	for (auto it = times.begin(); it != times.end();)
	{
		if (max < *it)
			max = *it;
		++it;

		if (num-- < 0)
			break;
	}

	return max;
}

float TickTimes::getAvg(int num) const
{
	double sum = 0;
	int idx = 0;

	for (auto it = times.begin(); it != times.end();)
	{
		sum += *it++;

		if (idx++ > num)
			break;
	}

	return static_cast<float>(sum / num);
}

std::string TickTimes::toString(int num) const
{
	return std::format("{:.2f}/{:.2f}/{:.2f}", getMin(num), getMax(num), getAvg(num));
}

std::string TickTimes::toTpsString(int num) const
{
	return std::format("{:.2f}/{:.2f}/{:.2f}", std::min(1000 / getMin(num), 20.f), std::min(1000 / getMax(num), 20.f), std::min(1000 / getAvg(num), 20.f));
}
