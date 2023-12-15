#pragma once
#include "ievent.hh"

template<class SubEvent>
class ICancelableEvent : public IEvent<SubEvent>
{
    bool canceled = false;

public:
    bool isCanceled() const
    {
        return canceled;
    }

    void setCanceled(bool canceled)
    {
        this->canceled = canceled;
    }
};
