#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include "Process.hpp"
#include "Timer.hpp"
#include <vector>
#include <string>

class Scheduler
{
public:
  Scheduler(Timer *timer) : m_Timer(timer) {}

  /**
   * Admit multiple process to the Scheduler
   */
  virtual void
  admit(std::vector<Process *> processes) = 0;

  /**
   * Admit a process to the Scheduler
   */
  virtual void admit(Process *process) = 0;

  /**
   * Returns the current process in the Scheduler
   */
  inline Process *currentProcess() const { return m_CurrentProcess; };

  /**
   * Returns true if the Scheduler is idle
   */
  inline bool isIdle() const { return m_IsIdle; };

  /**
   * Dispatch the next process in the Scheduler
   */
  virtual const std::string dispatch() = 0;

protected:
  Process *m_CurrentProcess;
  bool m_IsIdle;

  Timer *m_Timer;
};

#endif // SCHEDULER_HPP
