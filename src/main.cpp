#include "Process.hpp"
#include <stdio.h>

#include "Os.hpp"
#include "ProcessFileParser.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main() {
  Program powerpoint("powerpoint", 5);

  std::cout << "Program: " << powerpoint.name() << " Processing Time: " << powerpoint.processingTime() << std::endl;

  auto process = new Process(&powerpoint, 10);
  Os os { process };

  std::cout << "Process: " << process->id() << std::endl;

  ProcessFileParser parser; 
  auto processes = parser.parse("/Users/lulz/dev/os-scheduler/assets/samples/in.txt");

  std::cout << "Processes Count: " << processes.size() << std::endl;

  return 0;
}
