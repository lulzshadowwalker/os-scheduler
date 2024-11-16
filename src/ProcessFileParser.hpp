#ifndef PROCESS_FILE_PARSER_HPP
#define PROCESS_FILE_PARSER_HPP

#include "Process.hpp"
#include "Program.hpp"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class ProcessFileParser {
public:
  std::vector<Process *> parse(const std::string &filepath) {
    std::ifstream inputFile(filepath);
    if (!inputFile) {
      throw std::runtime_error("Error: Unable to open the file: " + filepath);
    }

    std::string line;
    std::vector<Process *> processes;

    //  NOTE: Ignores the first line if it exists which indicates the total
    //  number of processes in the file
    if (std::getline(inputFile, line)) {
      if (!isNumber(line)) {
        inputFile.seekg(0);
      }
    }

    int lineNumber = 0;
    while (std::getline(inputFile, line)) {
      lineNumber++;
      std::istringstream lineStream(line);

      std::string name;
      int arrivalTime, processingTime, rank;

      if (!(lineStream >> name >> arrivalTime >> processingTime >> rank)) {
        throw std::runtime_error("Invalid format on line " +
                                 std::to_string(lineNumber) + ": " + line);
      }

      int id = lineNumber;
      auto program = new Program(name, processingTime);
      auto process = new Process(program, lineNumber, rank);
      process->setArrivedAt(arrivalTime);
      process->setId(id);

      processes.push_back(process);
    }

    return processes;
  }

private:
  std::string m_FilePath;

  static bool isNumber(const std::string &str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
  }
};

#endif // PROCESS_FILE_PARSER_HPP
