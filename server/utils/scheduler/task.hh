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
	virtual ~Task() = default;

	virtual bool tick();

	ulong getId() const;
};
