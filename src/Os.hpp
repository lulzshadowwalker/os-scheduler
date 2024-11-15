#ifndef OS
#define OS

#include "Process.hpp"
#include "Program.hpp"
#include "Scheduler.hpp"
#include <initializer_list>
#include <vector>

class Os {

public:
  // Os(Scheduler scheduler, std::initializer_list<Process> processes)
  //: m_Scheduler(scheduler), m_Processes(processes) {};
  Os(std::initializer_list<Process *> processes) : m_Processes(processes) {};

  void run();
  Process execute(Program program);

private:
  Scheduler m_Scheduler;
  std::vector<Process *> m_Processes;
};

#endif // OS
