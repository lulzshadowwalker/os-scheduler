#include "RankingScheduler.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>

void RankingScheduler::admit(std::vector<Process *> processes)
{
  for (auto process : processes)
  {
    m_Processes.push_back(process);
  }

  markAsDirty();
}

void RankingScheduler::admit(Process *process)
{
  // Timestamp arrivedAt = m_Timer->time();
  // if (process->arrivedAt() != nullptr)
  // {
  //   //
  // }
  m_Processes.push_back(process);

  markAsDirty();
}

void RankingScheduler::schedule()
{
  //  NOTE: This works because we have overridden the < operator on the `Process` class
  std::sort(m_Processes.begin(), m_Processes.end());
  m_Dirty = false;

  if (m_Processes.size() > 0)
  {
    m_CurrentProcess = m_Processes[0];
    return;
  }

  m_CurrentProcess = nullptr;
}

const std::string RankingScheduler::dispatch()
{
  if (m_IsIdle)
    return "";

  //  NOTE: Only reschedule if the current state is dirty
  if (m_Dirty)
    schedule();

  Timestamp responseTime = m_Timer->time();
  m_CurrentProcess->execute();
  Timestamp turnaroundTime = m_Timer->diff(m_Timer->time(), m_CurrentProcess->arrivedAt());
  Timestamp delay = m_Timer->diff(m_CurrentProcess->turnaroundTime(), m_CurrentProcess->processingTime());

  std::ostringstream result;
  result << m_CurrentProcess->name() << ": (response=" << responseTime
         << ", turnaround=" << turnaroundTime
         << ", delay=" << delay << ")";

  m_Processes.erase(
      std::remove(
          m_Processes.begin(),
          m_Processes.end(),
          m_CurrentProcess),
      m_Processes.end());

  if (m_Processes.size() > 0)
  {
    m_CurrentProcess = m_Processes[0];
    return result.str();
  }

  m_CurrentProcess = nullptr;
  m_IsIdle = true;

  return result.str();
}
