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

  Program *program = new Program(&processes[0]);
  program->running->state = "running";
  program->running->startingTime = 0;

  for (auto i : processes)
  {
    program->arrivalMap[i.arrivalTime].push_back(i);
  }

  while (program->running || !program->blocked.empty() || !program->ready.empty() || program->arrivalMap.rbegin()->first >= cycle)
  {

    std::vector<Process> temp;

    if (!program->arrivalMap[cycle].empty())
    {
      for (auto i : program->arrivalMap[cycle])
      {
        if (program->running && *program->running != i)
        {
          i.state = "ready";
          program->ready.push_back(i);
        }
        else if (!program->running)
        {
          i.state = "ready";
          program->ready.push_back(i);
        }
      }
    }

    if (!program->running)
    {
      if (program->ready.size())
      {
        std::sort(program->ready.begin(), program->ready.end(), [](Process &a, Process &b) {
          return a.processID < b.processID;
        });

        Process dummy = program->ready.front();
        program->running = &dummy;
        program->running->state = "running";
        program->ready.pop_front();
      }
    }

    if (program->running)
    {
      program->running->state = "running";
      if (!program->running->cpuTime)
      {
        if (program->running->ioTime)
        {
          program->running->state = "blocked";
          program->running->ioTime--;
          program->blocked.push_back(*program->running);
        }
        else
          temp.push_back(*program->running);

        program->running = nullptr;
      }
      else
      {
        program->running->cpuTime--;
      }
    }

    if (!program->blocked.empty())
    {
      auto i = program->blocked.begin();
      while (i != program->blocked.end())
      {
        if (i->ioTime == 0)
        {
          program->ready.push_back(*i);
          program->blocked.erase(i++);
        }
        else
        {
          i->ioTime--;
          ++i;
        }
      }
    }

    if (program->running)
      temp.push_back(*program->running);

    for (auto i : program->blocked)
      temp.push_back(i);
    for (auto i : program->ready)
      temp.push_back(i);

    state.push_back(temp);

    cycle++;
  }

  return state;
}

#endif