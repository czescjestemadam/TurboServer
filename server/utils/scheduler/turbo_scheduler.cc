#include "turbo_scheduler.hh"

void TurboScheduler::tick()
{
	for (auto i = tasks.begin(); i != tasks.end();)
	{
		const std::unique_ptr<Task>& task = *i;
		bool remove = false;

		try
		{
			remove = task->tick();
		}
		catch (std::exception& e)
		{
			logger.error(e.what());
		}

		if (remove)
			i = tasks.erase(i);
		else
			++i;
	}
}

ulong TurboScheduler::task(const std::function<void()>& func, int tickDelay)
{
	std::unique_ptr<Task> task = std::make_unique<Task>(func, tickDelay);
	const ulong id = task->getId();
	tasks.push_back(std::move(task));
	return id;
}

ulong TurboScheduler::repeatingTask(const std::function<void()>& func, int tickDelay, int tickRepeating)
{
	std::unique_ptr<RepeatingTask> task = std::make_unique<RepeatingTask>(func, tickDelay, tickRepeating);
	const ulong id = task->getId();
	tasks.push_back(std::move(task));
	return id;
}

void TurboScheduler::remove(ulong id)
{
	std::erase_if(tasks, [id](std::unique_ptr<Task>& task)
	{ return task->getId() == id; });
}
