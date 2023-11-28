#pragma once
#include "../logger/logger.hh"
#include "repeating_task.hh"

#include <vector>
#include <memory>

class TurboScheduler
{
	Logger logger{ "TurboScheduler" };
	std::vector<std::unique_ptr<Task>> tasks;

public:
	void tick();

	ulong task(const std::function<void()>& func, int tickDelay);
	ulong repeatingTask(const std::function<void()>& func, int tickDelay, int tickRepeating);

	void remove(ulong id);
};
