#pragma once
#include "task.hh"

class RepeatingTask : public Task
{
	const int repeatingTicks;

public:
	RepeatingTask(const std::function<void()>& func, int remainingTicks, int repeatingTicks);

	bool tick() override;
};
