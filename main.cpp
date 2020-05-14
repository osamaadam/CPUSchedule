#include "fcfs.hpp"
#include "readFile.hpp"
#include <algorithm>
#include <iostream>

int main()
{
  std::vector<Process> processVec = readFile("input.txt");

  std::vector<std::vector<Process>> fcfsStats = fcfs(processVec);

  int index = 0;

  for (auto i : fcfsStats)
  {
    std::cout << index << " ";
    for (auto process : i)
    {
      std::cout << process.processID << ": " << process.state << " ";
    }
    std::cout << "\n";
    index++;
  }
}
