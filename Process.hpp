#ifndef PROCESSSTRUCT
#define PROCESSSTRUCT

#include <iostream>

struct Process
{
  int processID = -1;
  int cpuTime, ioTime, arrivalTime = 0;
  int turnaroundTime, finishingTime, startingTime = -1;
  std::string state = "waiting";

  Process(){};

  bool operator==(const struct Process &a) const
  {
    return (a.processID == this->processID);
  };
  bool operator!=(const struct Process &a) const
  {
    return (a.processID != this->processID);
  };
};

#endif