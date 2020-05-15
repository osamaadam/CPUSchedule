#ifndef TIMELINE
#define TIMELINE

#include "Process.hpp"
#include <vector>

struct Timeline
{
  std::vector<std::vector<Process>> state;
  std::vector<Process> processes;
};

#endif