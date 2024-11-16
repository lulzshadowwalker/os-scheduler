#include "Os.hpp"
#include "stdlib.h"
#include <iostream>
#include <fstream>

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

void prepareFile()
{
  if (std::ifstream("./out.txt"))
  {
    remove("./out.txt");
  }
}

void writeToFile(std::string output)
{
  if (output.back() != '\n')
  {
    output += "\n";
  }

  std::ofstream out;

  out.open("./out.txt", std::ios::app);
  out << output;
  out.close();
}

void Os::run()
{
  DEBUG(std::cout << "[DEBUG] OS Starting Up..." << std::endl);

  //  NOTE: If scheduler still has processes to handle
  prepareFile();
  while (!m_Scheduler->isIdle())
  {
    m_Timer->tick(); //  NOTE: Simulating a single time quantum
    std::string output = m_Scheduler->dispatch();
    writeToFile(output);
    DEBUG(std::cout << "[DEBUG] " << output << std::endl);
  }

  DEBUG(std::cout << "[DEBUG] OS Shutting Down ..." << std::endl);
}

Process *Os::execute(Program program)
{
  int id = m_Processes.size() + 1;
  return new Process(&program, id, 0);
}
