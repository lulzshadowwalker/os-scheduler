#ifndef OS
#define OS

#include "Process.hpp"
#include "Program.hpp"
#include "Scheduler.hpp"
#include <vector>
#include "Timer.hpp"

class Os
{
public:
  Os(Scheduler *scheduler, Timer *timer) : m_Scheduler(scheduler), m_Timer(timer) {};
  Os(Scheduler *scheduler, Timer *timer, std::vector<Process *> processes);

  void run();

  Process *execute(Program program);

private:
  Scheduler *m_Scheduler;
  Timer *m_Timer;
  std::vector<Process *> m_Processes;
};

#endif // OS
