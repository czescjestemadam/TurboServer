#pragma once

#include <type_traits>

template<typename Event>
class EventListener
{
    // static_assert(std::is_base_of_v<IEvent, Event>, "template Event is not derived from IEvent");

public:
    EventListener()
    {
        Event::LISTENERS.push_back(this);
    }

    virtual ~EventListener()
    {
        Event::LISTENERS.erase(this);
    }

    virtual void onEvent(Event& e) = 0;
};
