#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <string>

using Time = int;

class Program
{
public:
  Program(std::string name, Time processingTime)
      : m_Name(name), m_ProcessingTime(processingTime) {};

  inline std::string name() const { return m_Name; }
  inline Time processingTime() const { return m_ProcessingTime; }

private:
  std::string m_Name;
  Time m_ProcessingTime;
};

#endif // PROGRAM_HPP
