#include "ticker.hh"

static constexpr std::chrono::milliseconds TICK_DURATION{ 50 };

Ticker::Ticker(std::function<void()>&& tick) : tick(std::move(tick))
{
}

void Ticker::start()
{
	if (running)
		return;

	running = true;

	th = std::thread(std::bind(&Ticker::tickLoop, this));
}

void Ticker::stop()
{
	if (!running)
		return;

	running = false;
	th.join();
}


TickTimes& Ticker::getTimes()
{
	return times;
}

ulong Ticker::getTickCount() const
{
	return tickCount;
}

float Ticker::getTickDelta() const
{
	auto micro = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - lastTickStart);
	return (float)micro.count() / 1000.f;
}


void Ticker::tickLoop()
{
	while (running)
	{
		try
		{
			lastTickStart = std::chrono::system_clock::now();

			tick();

			times.add(getTickDelta());
			++tickCount;

			if (std::chrono::system_clock::now() - lastTickStart < TICK_DURATION)
				std::this_thread::sleep_until(lastTickStart + TICK_DURATION);
		}
		catch (std::exception& e)
		{
			logger.error("tick(): {}", e.what());
			continue;
		}
	}
}
