#ifndef TIMER_HPP
#define TIMER_HPP

using Timestamp = int;

class Timer
{
public:
    /**
     * Waits for the next tick.
     */
    virtual void tick() = 0;

    /**
     * Returns the time since the timer device has started.
     */
    virtual Timestamp time() const = 0;

    inline Timestamp diff(time_t last, time_t first) const
    {
        return static_cast<int>(std::difftime(last, first));
    }
};

#endif // TIMER_HPP