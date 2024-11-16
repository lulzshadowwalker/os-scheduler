#ifndef REAL_TIME_TIMER
#define REAL_TIME_TIMER

#include <ctime>
#include "Timer.hpp"

class RealTimeTimer : public Timer
{
public:
  RealTimeTimer();

  /**
   * Waits for the next tick (One second).
   */
  void tick() override;

  /**
   * Returns the time in seconds since the timer device has started.
   */
  Timestamp time() const override;

private:
  /**
   * The time when the timer was started.
   */
  time_t m_StartedAt;

  inline time_t now() const { return std::time(nullptr); }
};

#endif // REAL_TIME_TIMER
