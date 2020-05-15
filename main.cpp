#include "Timeline.hpp"
#include "fcfsScheduling.hpp"
#include "printStats.hpp"
#include "readFile.hpp"
#include "roundRobin.hpp"
#include <algorithm>
#include <iostream>

int main()
{
  std::vector<Process> processVec = readFile("input.txt");

  // Timeline fcfsStats = fcfsScheduling(processVec);
  // printStats(fcfsStats);

  Timeline roundRobinStats = roundRobin(processVec, 10);
  printStats(roundRobinStats);
}
