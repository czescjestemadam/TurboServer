#include "task.hh"

static ulong IDX = 0;

Task::Task(const std::function<void()>& func, int remainingTicks) : func(func), remainingTicks(remainingTicks), id(IDX++)
{
}

bool Task::tick()
{
	if (remainingTicks-- > 0)
		return false;

	func();
	return true;
}

ulong Task::getId() const
{
	return id;
}
