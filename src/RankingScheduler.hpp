#ifndef RANKING_SCHEDULER
#define RANKING_SCHEDULER

#include "Scheduler.hpp"
#include "Timer.hpp"
#include <vector>

class RankingScheduler : public Scheduler
{
public:
  RankingScheduler(Timer *timer) : Scheduler(timer) {}

  /**
   * Admit multiple processes to the Scheduler
   */
  void admit(std::vector<Process *> processes) override;

  /**
   * Admit a process to the Scheduler
   */
  void admit(Process *process) override;

  inline void markAsDirty() { m_Dirty = true; }

  const std::string dispatch() override;

private:
  std::vector<Process *> m_Processes;

  /**
   * Flag to indicate if the processes need to be rescheduled
   */
  bool m_Dirty = false;

  /**
   * Schedule the processes
   *
   * The main aspect of Ranking Scheduling Algorithm is the rank value for each
   * process (3rd column). We always give priority for process that are ranked
   * first (i.e. lower ranking value). However, If multiple processes have the
   * same ranking value, we decide based on the arrival time. In the case where
   * processes have the same ranking and arrival time, we choose the process
   * that had its name listed first in the input file.
   */
  void schedule();
};

#endif // RANKING_SCHEDULER
