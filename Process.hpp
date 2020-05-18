#ifndef PROCESSSTRUCT
#define PROCESSSTRUCT

#include <iostream>

struct Process
{
  int processID = -1;
  int cpuTime, ioTime, arrivalTime, pseudoArrivalTime, quanta = -1;
  int turnaroundTime, finishingTime, startingTime = -1;
  std::string state = "waiting";

  Process(int processID, int cpuTime, int ioTime, int arrivalTime)
      : processID(processID), cpuTime(cpuTime), ioTime(ioTime), arrivalTime(arrivalTime), pseudoArrivalTime(arrivalTime){};

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