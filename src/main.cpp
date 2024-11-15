#include "Process.hpp"
#include <stdio.h>

#include "Os.hpp"
#include "iostream"

int main() {

  Program powerpoint("powerpoint", 5);

  std::cout << "Program: " << powerpoint.name() << " Processing Time: " << powerpoint.processingTime() << std::endl;

  auto process = new Process(&powerpoint, 10);
  Os os { process };

  std::cout << "Process: " << process->id() << std::endl;

  return 0;
}
