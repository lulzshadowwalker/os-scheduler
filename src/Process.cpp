#include "Process.hpp"
#include "ProcessState.hpp"

Process::Process(const class Program *program, Rank rank)
    : m_Program(program), m_Rank(rank) {
  m_State = ProcessState::NEW;
}
