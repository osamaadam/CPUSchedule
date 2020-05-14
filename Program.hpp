#ifndef PROGRAMSTRUCT
#define PROGRAMSTRUCT

#include "Process.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <vector>

struct Program
{
  Process *running;
  std::list<Process> blocked;
  std::deque<Process> ready;
  std::map<int, std::vector<Process>> arrivalMap;

  Program(Process *running)
  {
    this->running = running;
  }
  Program() { running = nullptr; }
};

#endif