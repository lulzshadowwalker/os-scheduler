#ifndef MOCK_TIMER_HPP
#define MOCK_TIMER_HPP

#include "Timer.hpp"

class MockTimer : public Timer
{
public:
    /**
     * Waits for the next tick.
     */
    inline void tick()
    {
        m_Time++;
    };

    /**
     * Returns the time since the timer device has started.
     */
    Timestamp time() const
    {
        return m_Time;
    };

private:
    Timestamp m_Time = 0;
};

#endif // MOCK_TIMER_HPP