#pragma once
#include <vector>
#include <thread>
#include <functional>
#include <deque>
#include <mutex>
#include <condition_variable>

class ThreadPool
{
	bool running = false;

	std::vector<std::thread> threads;

	std::deque<std::function<void()>> tasks;
	std::mutex tasksMx;
	std::condition_variable tasksCv;

public:
	ThreadPool() = default;
	explicit ThreadPool(int threadnum);
	~ThreadPool();

	void start(int threadnum);
	void stop();
	void waitStop();
	void waitDone();

	void queue(const std::function<void()>& func);

private:
	void loop();
};
