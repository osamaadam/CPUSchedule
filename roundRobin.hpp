#ifndef ROUNDROBIN
#define ROUNDROBIN

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <vector>

#include "Process.hpp"
#include "Timeline.hpp"

Timeline roundRobin(std::vector<Process> &processes, int quanta) {
  Timeline returnStruct;
  int cycle = 0;

  std::sort(processes.begin(), processes.end(), [](auto &a, auto &b) {
    return a.arrivalTime < b.arrivalTime;
  });

  Process *running = nullptr;
  std::list<Process> blocked;
  std::deque<Process> ready;
  std::map<int, std::vector<Process> > arrivalMap;

  for (auto &i: processes) {
    arrivalMap[i.arrivalTime].push_back(i);
  }

  while (running || !blocked.empty() || !ready.empty() || arrivalMap.rbegin()->first > cycle) {
    std::vector<Process> temp;

    if (running && !running->cpuTime && !running->ioTime) {
      running->finishingTime = cycle - 1;
      running->turnaroundTime = running->finishingTime - running->startingTime + 1;
      running->state = "terminated";
      returnStruct.processes.push_back(*running);
      running = nullptr;
    } else if (running && !running->quanta && running->cpuTime) {
      running->state = "ready";
      running->pseudoArrivalTime = cycle;
      ready.push_back(*running);
      running = nullptr;
    } else if (running && (!running->quanta || !running->cpuTime) && running->ioTime) {
      running->state = "blocked";
      blocked.push_back(*running);
      running = nullptr;
    }

    if (!arrivalMap[cycle].empty()) {
      for (auto &i: arrivalMap[cycle]) {
        i.state = "ready";
        if (i.startingTime == -1)
          i.startingTime = cycle;
        ready.push_back(i);
      }
    }

    if (!blocked.empty()) {
      auto i = blocked.begin();
      while (i != blocked.end()) {
        if (i->ioTime == 0) {
          i->pseudoArrivalTime = cycle;
          i->state = "ready";
          ready.push_back(*i);
          i = blocked.erase(i);
        } else {
          i->ioTime--;
          ++i;
        }
      }
    }

    if (!running && !ready.empty()) {
      if (ready.size() > 1)
        std::sort(ready.begin(), ready.end(), [](Process &a, Process &b) {
          if (a.pseudoArrivalTime == b.pseudoArrivalTime)
            return a.processID < b.processID;
          return a.pseudoArrivalTime < b.pseudoArrivalTime;
        });

      auto dummy = ready.front();
      running = &dummy;
      running->quanta = quanta;
      running->state = "running";
      ready.pop_front();
    }

    if (running && running->cpuTime && running->quanta) {
      running->cpuTime--;
      running->quanta--;
    }

    if (running)
      temp.push_back(*running);

    for (auto const &i: blocked)
      temp.push_back(i);

    for (auto const &i: ready)
      temp.push_back(i);

    if (!temp.empty())
      returnStruct.state.push_back(temp);

    cycle++;
  }
  return returnStruct;
}

#endif