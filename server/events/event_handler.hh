#pragma once
#include "ievent_listener.hh"

#include <vector>

template<class Ev>
class EventHandler
{
	std::vector<IEventListener<Ev>*> LISTENERS;

	EventHandler() = default;

public:
	static void registerListener(IEventListener<Ev>& listener)
	{
		get().LISTENERS.push_back(&listener);
	}

	static void unregisterListener(IEventListener<Ev>& listener)
	{
		get().LISTENERS.erase(std::find(get().LISTENERS.begin(), get().LISTENERS.end(), &listener));
	}

	static void call(Ev& event)
	{
		for (IEventListener<Ev>* listener : get().LISTENERS)
			listener->onEvent(event);
	}

private:
	static EventHandler& get()
	{
		static EventHandler handler;
		return handler;
	}
};
