#pragma once
#include "tick_times.hh"
#include "server/utils/logger/logger.hh"

#include <thread>
#include <functional>
#include <chrono>

class Ticker
{
	Logger logger{ "Ticker" };

	bool running = false;
	std::thread th;

	std::function<void()> tick;
	std::chrono::time_point<std::chrono::system_clock> lastTickStart;

	TickTimes times{ 72000 }; // 20 * 60 * 60 / 1h
	ulong tickCount = 0;

public:
	explicit Ticker(std::function<void()>&& tick);

	void start();
	void stop();

	TickTimes& getTimes();
	ulong getTickCount() const;
	float getTickDelta() const;

private:
	void tickLoop();
};
