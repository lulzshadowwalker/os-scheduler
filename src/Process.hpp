#ifndef PROCESS_HPP
#define PROCESS_HPP

#include "ProcessState.hpp"
#include "Program.hpp"
#include <string>

using Rank = int;
using Timestamp = int;

class Process {

public:
  Process(const Program* program, Rank rank);

  inline int id() const { return m_Id; }
  inline std::string name() const { return m_Program->name(); }
  inline ProcessState state() const { return m_State; }
  inline const Program* program() const { return m_Program; }
  inline Rank rank() const { return m_Rank; }
  inline Timestamp arrivedAt() const { return m_ArrivedAt; }

private:
  int m_Id;
  std::string m_Name;
  ProcessState m_State;
  const Program* m_Program;
  Timestamp m_ArrivedAt;
  Rank m_Rank;
};

#endif // PROCESS_HPP
