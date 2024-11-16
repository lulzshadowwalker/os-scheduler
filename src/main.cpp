#include "Process.hpp"
#include <stdio.h>

#include "Os.hpp"
#include "ProcessFileParser.hpp"
#include "RankingScheduler.hpp"
#include <iostream>
#include <string>
#include "RealTimeTimer.hpp"
#include "MockTimer.hpp"

int main(const int argc, const char *argv[])
{
  std::string filepath = "../in.txt";
  if (argc > 1)
  {
    filepath = argv[1];
  }

  // check if should use real time timer
  bool isRealTime = (argc > 2 && std::string(argv[2]) == "--realtime");

  std::vector<Process *>
      processes;
  try
  {
    ProcessFileParser parser;
    processes = parser.parse("../in.txt");
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

  // auto timer = new RealTimeTimer();
  Timer *timer = new MockTimer();
  if (isRealTime)
  {
    timer = new RealTimeTimer();
  }

  auto scheduler = new RankingScheduler(timer);
  Os os(scheduler, timer, processes);

  os.run();

  return 0;
}
