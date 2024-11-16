#include "RealTimeTimer.hpp"
#include <thread>

RealTimeTimer::RealTimeTimer() { m_StartedAt = now(); }

void RealTimeTimer::tick()
{
    time_t current = now();

    while (diff(now(), current) == 0)
    {
        //
    }
}

Timestamp RealTimeTimer::time() const { return diff(now(), m_StartedAt); }