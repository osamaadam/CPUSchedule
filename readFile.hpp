#ifndef READFILE
#define READFILE

#include "Process.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

std::vector<Process> readFile(std::string fileName)
{
  std::vector<Process> processVec;
  std::ifstream inputFile(fileName);
  std::string line;
  std::string token;
  std::vector<std::vector<std::string>> lineVec;

  if (inputFile.is_open())
  {
    while (getline(inputFile, line))
    {
      std::vector<std::string> tempProcessVec;
      std::stringstream stream(line);
      while (stream >> token)
      {
        tempProcessVec.push_back(token);
      }
      lineVec.push_back(tempProcessVec);
    }
    inputFile.close();
  }

  for (auto i = lineVec.begin(); i < lineVec.end(); i++)
  {
    if ((*i).size() == 4)
    {
      Process process;
      process.processID = std::stoi((*i)[0]);
      process.cpuTime = std::stoi((*i)[1]);
      process.ioTime = std::stoi((*i)[2]);
      process.arrivalTime = std::stoi((*i)[3]);
      processVec.push_back(process);
    }
  }

  return processVec;
}

#endif