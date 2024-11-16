#include "RankingScheduler.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>

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

void bubbleSort(std::vector<Process *>& processes) {
    for (size_t i = 0; i < processes.size(); ++i) {
        for (size_t j = 0; j < processes.size() - i - 1; ++j) {
            Process*& a = processes[j];
            Process*& b = processes[j + 1];

            bool shouldSwap = false;
            if (a->rank() < b->rank()) {
                shouldSwap = true; 
            } else if (a->rank() == b->rank()) {
                if (a->arrivedAt() > b->arrivedAt()) {
                    shouldSwap = true; 
                } else if (a->arrivedAt() == b->arrivedAt()) {
                    if (a->id() > b->id()) {
                        shouldSwap = true; 
                    }
                }
            }

            if (shouldSwap) {
                std::swap(processes[j], processes[j + 1]);
            }
        }
    }
}

void RankingScheduler::schedule()
{
  //  NOTE: This works because we have overridden the < operator on the `Process` class
  bubbleSort(m_Processes);
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

  Timestamp responseTime = m_Timer->time() - m_CurrentProcess->arrivedAt();
  // m_CurrentProcess->execute();

  //  NOTE: Simulate the processing time
  for (int i = 0; i < m_CurrentProcess->processingTime(); i++)
  {
    m_Timer->tick();
  }

  Timestamp turnaroundTime = m_Timer->diff(m_Timer->time(), m_CurrentProcess->arrivedAt());
  Timestamp delay = abs(m_Timer->diff(m_CurrentProcess->turnaroundTime(), m_CurrentProcess->processingTime()));

  std::ostringstream result;
  result << m_CurrentProcess->name() << ": (response=" << responseTime
         << ", turnaround=" << turnaroundTime
         << ", delay=" << delay << ")" << " rank=" << m_CurrentProcess->rank() << std::endl << " Arrived at: " << m_CurrentProcess->arrivedAt() << std::endl;

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
