#include "fcfsScheduling.hpp"
#include "readFile.hpp"
#include "writeToFile.hpp"
#include <algorithm>
#include <iostream>

int main()
{
  std::vector<Process> processVec = readFile("input.txt");
  float activityTime = 0;

  Timeline fcfsStats = fcfsScheduling(processVec);
  std::string content;

  int index = 0;

  for (auto i : fcfsStats.state)
  {

    std::sort(i.begin(), i.end(), [](Process a, Process b) {
      return a.processID < b.processID;
    });

    content += std::to_string(index);
    content += " ";
    for (auto process : i)
    {
      content += std::to_string(process.processID) + ": " + process.state + " ";
      if (process.state == "running")
        activityTime++;
    }
    content += "\n";
    index++;
  }

  content += "\nFinishing Time: " + std::to_string(fcfsStats.state.size() - 1) + "\n";
  content += "CPU utilization: " + std::to_string((activityTime / fcfsStats.state.size())) + "\n";

  std::sort(fcfsStats.processes.begin(), fcfsStats.processes.end(), [](Process a, Process b) {
    return a.processID < b.processID;
  });

  for (auto i : fcfsStats.processes)
  {
    content += "Turnaround time of process " + std::to_string(i.processID) + ": ";
    content += std::to_string(i.turnaroundTime) + "\n";
  }

  writeToFile("outputFCFS.txt", content);
}
