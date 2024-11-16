#ifndef PROCESS_HPP
#define PROCESS_HPP

#include "ProcessState.hpp"
#include "Program.hpp"
#include <string>

using Rank = int;
using Timestamp = int;

class Process
{

public:
  Process(const Program *program, int id, Rank rank);

  inline int id() const { return m_Id; }
  inline std::string name() const { return m_Program->name(); }
  inline ProcessState state() const { return m_State; }
  inline const Program *program() const { return m_Program; }
  inline Rank rank() const { return m_Rank; }
  inline Timestamp arrivedAt() const { return m_ArrivedAt; }
  inline Timestamp responseTime() const { return m_ResponseTime; }
  inline Timestamp turnaroundTime() const { return m_TurnaroundTime; }
  inline Timestamp delay() const { return m_Delay; }
  inline Time processingTime() const { return m_Program->processingTime(); }

  inline Process &setResponseTime(Timestamp responseTime)
  {
    m_ResponseTime = responseTime;

    return *this;
  }

  inline Process &setTurnaroundTime(Timestamp turnaroundTime)
  {
    m_TurnaroundTime = turnaroundTime;

    return *this;
  }

  inline Process &setDelay(Timestamp delay)
  {
    m_Delay = delay;

    return *this;
  }

  inline Process &setArrivedAt(Timestamp arrivedAt)
  {
    m_ArrivedAt = arrivedAt;

    return *this;
  }

  inline Process &setId(int id)
  {
    m_Id = id;

    return *this;
  }

  void execute();

  bool operator<(const Process &other) const;

private:
  int m_Id;
  ProcessState m_State;
  const Program *m_Program;
  Timestamp m_ArrivedAt;
  Timestamp m_ResponseTime;
  Timestamp m_TurnaroundTime;
  Timestamp m_Delay;
  Rank m_Rank;
};

#endif // PROCESS_HPP
