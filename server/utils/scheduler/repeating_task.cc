#include "repeating_task.hh"

RepeatingTask::RepeatingTask(const std::function<void()>& func, int remainingTicks, int repeatingTicks) :
		Task(func, remainingTicks), repeatingTicks(repeatingTicks)
{
}

bool RepeatingTask::tick()
{
	if (Task::tick())
		remainingTicks = repeatingTicks;
	return false;
}
