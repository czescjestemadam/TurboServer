#pragma once

#include <functional>

class Task
{
protected:
	const ulong id;
	const std::function<void()> func;
	int remainingTicks;

public:
	Task(const std::function<void()>& func, int remainingTicks);

	virtual bool tick();

	const ulong getId() const;
};
