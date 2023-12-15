#pragma once
#include <vector>
#include <string>

// template<class Event>
// class EventListener;
#include "event_listener.hh"

template<class SubEvent>
class IEvent
{
protected:
    static std::vector<EventListener<SubEvent>*> LISTENERS;
    friend EventListener<SubEvent>;
public:


    virtual ~IEvent() = default;

    virtual std::string getName() const = 0;

    virtual std::string toString() const = 0;


    static void call(SubEvent& event);
};

template <class SubEvent>
void IEvent<SubEvent>::call(SubEvent& event)
{
    for (EventListener<SubEvent>* listener : LISTENERS)
        listener->onEvent(event);
}
