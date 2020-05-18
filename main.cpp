#include <iostream>

#include "Timeline.hpp"
#include "firstServed.hpp"
#include "printStats.hpp"
#include "prompt.hpp"
#include "readFile.hpp"
#include "roundRobin.hpp"

int main() {
  Choice choice = prompt();
  std::vector<Process> processVec = readFile("input.txt");
  Timeline stats;

  switch (choice.mode) {
    case 0:
      stats = firstServed(processVec);
      printStats("outputFCFS.txt", stats);
      break;
    case 1:
      stats = roundRobin(processVec, choice.quanta);
      printStats("outputRR.txt", stats);
      break;
    default:
      break;
  }
}
