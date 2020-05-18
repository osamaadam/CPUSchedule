#ifndef TIMELINE
#define TIMELINE

#include <vector>

#include "Process.hpp"

struct Timeline {
  std::vector<std::vector<Process>> state;
  std::vector<Process> processes;
};

#endif