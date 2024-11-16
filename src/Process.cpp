#include "Process.hpp"
#include "ProcessState.hpp"
#include "stdlib.h"
#include <thread>

Process::Process(const class Program *program, int id, Rank rank)
    : m_Program(program), m_Id(id), m_Rank(rank), m_State(ProcessState::NEW) {}

bool Process::operator<(const Process &other) const
{
  if (m_Rank != other.rank())
  {
    return m_Rank < other.rank();
  }

  if (m_ArrivedAt != other.arrivedAt())
  {
    return m_ArrivedAt < other.arrivedAt();
  }

  return name() < other.name();
}

void Process::execute()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(1000 * m_Program->processingTime()));
}
