#ifndef FCFS
#define FCFS

#include "Process.hpp"
#include "Program.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<Process>> fcfs(std::vector<Process> &processes)
{
  std::vector<std::vector<Process>> state;
  std::vector<Process> temp;
  int cycle = 0;

  std::sort(processes.begin(), processes.end(), [](Process a, Process b) {
    return a.arrivalTime < b.arrivalTime;
  });

  Process *running = nullptr;
  std::list<Process> blocked;
  std::deque<Process> ready;
  std::map<int, std::vector<Process>> arrivalMap;

  for (auto i : processes)
  {
    arrivalMap[i.arrivalTime].push_back(i);
  }

  while (running || !blocked.empty() || !ready.empty() || arrivalMap.rbegin()->first >= cycle)
  {

    std::vector<Process> temp;

    if (!arrivalMap[cycle].empty())
    {
      for (auto j = arrivalMap[cycle].begin(); j != arrivalMap[cycle].end(); j++)
      {
        j->state = "ready";
        ready.push_back(*j);
      }
    }

    if (!blocked.empty())
    {
      auto i = blocked.begin();
      while (i != blocked.end())
      {
        if (i->ioTime == 0)
        {
          ready.push_back(*i);
          blocked.erase(i++);
        }
        else
        {
          i->ioTime--;
          ++i;
        }
      }
    }

    if (!running && ready.size())
    {
      std::sort(ready.begin(), ready.end(), [](Process a, Process b) {
        return a.processID < b.processID;
      });

      Process dummy = ready.front();
      running = &dummy;
      running->state = "running";
      running->startingTime = cycle;
      ready.pop_front();
    }

    if (running)
    {
      if (!running->cpuTime)
      {
        if (running->ioTime)
        {
          running->state = "blocked";
          running->ioTime--;
          blocked.push_back(*running);
        }
        else
          temp.push_back(*running);

        running = nullptr;
      }
      else
      {
        running->cpuTime--;
      }
    }

    if (running)
      temp.push_back(*running);

    for (auto i : blocked)
      temp.push_back(i);
    for (auto i : ready)
      temp.push_back(i);

    state.push_back(temp);

    cycle++;
  }
  return state;
}

#endif