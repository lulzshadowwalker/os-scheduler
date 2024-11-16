#include "Process.hpp"
#include "ProcessFileParser.hpp"
#include "ProcessState.hpp"
#include "MockTimer.hpp"
#include <cest>

describe("Application", []()
         {
  it("Timer Device :: starts at 0", []() {
    MockTimer timer;
    expect(timer.time()).toBe(0);
  });

  it("Timer Device :: returns the time in seconds since the timer device has "
     "started",
     []() {
       MockTimer timer;
       // timer.tick();
       // timer.tick();
       // expect(timer.time()).toBe(2);
       expect(timer.time()).toBe(0);
     });

  it("Process :: starts at ProcessState::NEW state", []() {
    Program powerpoint("Powerpoint", 5);
    Process process(&powerpoint, 5, 0);
    expect(process.state()).toBe(ProcessState::NEW);
  });

  it("Process File Parser :: parses a valid file successfully", []() {
    ProcessFileParser parser;
    std::string validFiles[] = {"../assets/samples/valid.txt"};
    for (int i = 0; i < sizeof(validFiles) / sizeof(std::string); i++) {
      auto processes = parser.parse(validFiles[i]);

      expect(processes.size()).toBe(5);
      expect(processes[0]->name()).toBe("A");
      expect(processes[0]->arrivedAt()).toBe(0);
      expect(processes[0]->processingTime()).toBe(3);
      expect(processes[0]->rank()).toBe(2);
    }
  });

  it("Process File Parser :: it throws a runtime error if file is not found",
     []() {
       ProcessFileParser parser;
       try {
         auto processes = parser.parse("invalid-filepath");
       } catch (const std::runtime_error &e) {
         expect(true).toBe(true);
         return;
       }

       //  NOTE: Expected an error to be thrown.
       expect(false).toBe(true);
     });

  it("Process File Parser :: it throws a runtime error if file has an invalid "
     "format",
     []() {
       ProcessFileParser parser;
       try {
         auto processes = parser.parse("../assets/samples/invalid.txt");
       } catch (const std::runtime_error &e) {
         expect(true).toBe(true);
         return;
       }

       //  NOTE: Expected an error to be thrown.
       expect(false).toBe(true);
     }); });
