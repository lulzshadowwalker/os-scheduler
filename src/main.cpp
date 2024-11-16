#include "Process.hpp"
#include <stdio.h>

#include "Os.hpp"
#include "ProcessFileParser.hpp"
#include "RankingScheduler.hpp"
#include <iostream>
#include <string>
#include "RealTimeTimer.hpp"

int main()
{
  std::vector<Process *> processes;
  try
  {
    ProcessFileParser parser;
    processes = parser.parse("../assets/samples/in.txt");
  }
  catch (const std::runtime_error &e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  catch (...)
  {
    std::cerr << "Error: An unexpected error occurred.\n";
    return 1;
  }

  auto timer = new RealTimeTimer();

  auto scheduler = new RankingScheduler(timer);
  Os os(scheduler, timer, processes);

  os.run();

  return 0;
}
