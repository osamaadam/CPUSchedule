#ifndef PROGRAMSTRUCT
#define PROGRAMSTRUCT

#include "Process.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <map>

struct Program
{
  Process *running;
  std::list<Process> blocked;
  std::deque<Process> ready;
  std::map<int, std::deque<Process>> arrivalMap;

  Program(Process *running)
  {
    this->running = running;
  }
  Program() { running = nullptr; }
};

#endif