#include "Timer.hpp"

Timer::Timer() { m_StartedAt = std::time(nullptr); }

void Timer::tick() {
  time_t current = now();

  while (diff(now(), current) == 0) {
    //
  }
}

Timestamp Timer::time() const { return diff(now(), m_StartedAt); }

Timestamp Timer::diff(time_t last, time_t first) const {
  return static_cast<int>(std::difftime(last, first));
}
