#include "thread_pool.hh"

#include "../logger/logger.hh"
static Logger log{ "ThreadPool" };

ThreadPool::ThreadPool(int threadnum)
{
	start(threadnum);
}

ThreadPool::~ThreadPool()
{
	waitStop();
}

void ThreadPool::start(int threadnum)
{
	if (running)
		return;

	log.info("starting {} threads", threadnum);

	running = true;

	for (int i = 0; i < threadnum; ++i)
		threads.emplace_back(&ThreadPool::loop, this);
}

void ThreadPool::stop()
{
	if (!running)
		return;

	running = false;

	log.info("stopping");
}

void ThreadPool::waitStop()
{
	if (!running)
		return;

	log.info("wait stopping");

	running = false;
	tasksCv.notify_all();

	for (std::thread& th : threads)
		th.join();

	threads.clear();
}

void ThreadPool::waitDone()
{
	// todo
}

void ThreadPool::queue(const std::function<void()>& func)
{
	{
		std::unique_lock lock(tasksMx);
		tasks.push_back(func);
	}

	log.info("queued {} task", tasks.size());

	tasksCv.notify_one();
}

void ThreadPool::loop()
{
	while (true)
	{
		std::function<void()> task;

		{
			std::unique_lock lock(tasksMx);
			if (tasks.empty())
			{
				log.info("loop: waiting on tasks");
				tasksCv.wait(lock);
			}

			if (tasks.empty() && !running)
			{
				log.info("loop: tasks empty && not running, return");
				return;
			}

			task = tasks.front();
			tasks.pop_front();
		}

		task();
		log.info("loop: task executed");
	}
}
