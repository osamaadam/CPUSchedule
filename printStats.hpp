#ifndef PRINTSTATS
#define PRINTSTATS

#include <algorithm>
#include <iostream>

#include "Timeline.hpp"
#include "writeToFile.hpp"

std::string printStats(std::string fileName, Timeline stats) {
  std::string content;
  float activityTime = 0;

  int index = 0;

  for (auto i: stats.state) {
    std::sort(i.begin(), i.end(), [](Process a, Process b) {
      return a.processID < b.processID;
    });

    content += std::to_string(index);
    content += " ";
    for (auto const &process: i) {
      content += std::to_string(process.processID) + ": " + process.state + " ";
      if (process.state == "running") activityTime++;
    }
    content += "\n";
    index++;
  }

  std::string cpuUtilization = std::to_string((activityTime / stats.state.size()) * 100);
  if (*(cpuUtilization.begin() + 2) != '0')
    cpuUtilization.replace(cpuUtilization.begin() + 2, cpuUtilization.end(), "");
  else
    cpuUtilization.replace(cpuUtilization.begin() + 3, cpuUtilization.end(), "");

  content += "\nFinishing Time: " + std::to_string(stats.state.size() - 1) + "\n";
  content += "CPU utilization: " + cpuUtilization + "%\n";

  std::sort(stats.processes.begin(), stats.processes.end(), [](Process a, Process b) {
    return a.processID < b.processID;
  });

  for (auto const &i: stats.processes) {
    content += "Turnaround time of process " + std::to_string(i.processID) + ": ";
    content += std::to_string(i.turnaroundTime) + "\n";
  }

  writeToFile(fileName, content);
  std::cout << "Writing done!\n"
            << "Please check " << fileName << "!"
            << "\n";

  return content;
}

#endif