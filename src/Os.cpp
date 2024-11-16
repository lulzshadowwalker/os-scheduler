#include "Os.hpp"
#include "stdlib.h"
#include <iostream>

#ifdef DEBUG
#define DEBUG(statement) statement
#else
#define DEBUG(statement) ((void)0)
#endif

Os::Os(Scheduler *scheduler, Timer *timer, std::vector<Process *> processes)
    : m_Processes(processes), m_Timer(timer), m_Scheduler(scheduler)
{
  m_Scheduler->admit(processes);
};

void Os::run()
{
  DEBUG(std::cout << "[DEBUG] OS Starting Up..." << std::endl);

  //  NOTE: If scheduler still has processes to handle
  while (!m_Scheduler->isIdle())
  {
    m_Timer->tick(); //  NOTE: Simulating a single time quantum
    std::string output = m_Scheduler->dispatch();
    DEBUG(std::cout << "[DEBUG] " << output << std::endl);
  }

  DEBUG(std::cout << "[DEBUG] OS Shutting Down ..." << std::endl);
}

Process *Os::execute(Program program)
{
  int id = m_Processes.size() + 1;
  return new Process(&program, id, 0);
}
