#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>

using Timestamp = int;

class Timer {

public:
  Timer();

  /**
   * Waits for the next tick (One second).
   */
  void tick();

  /**
   * Returns the time in seconds since the timer device has started.
   */
  Timestamp time() const;

private:
  /**
   * The time when the timer was started.
   */
  time_t m_StartedAt;

  inline time_t now() const { return std::time(nullptr); }

  /**
   * Returns the difference between two timestamps in seconds (Timestamp).
   */
  Timestamp diff(time_t a, time_t b) const;
};

#endif // TIMER_HPP
