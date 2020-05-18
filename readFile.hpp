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
  std::vector<std::vector<std::string>> lineVec;

  if (inputFile.is_open())
  {
    std::string line;
    while (getline(inputFile, line))
    {
      std::vector<std::string> tempProcessVec;
      std::stringstream stream(line);
      std::string token;
      while (stream >> token)
      {
        tempProcessVec.push_back(token);
      }
      lineVec.push_back(tempProcessVec);
    }
    inputFile.close();
  }

  for (auto i : lineVec)
  {
    if (i.size() == 4)
    {
      Process process(std::stoi(i[0]), std::stoi(i[1]), std::stoi(i[2]), std::stoi(i[3]));
      processVec.push_back(process);
    }
    else
    {
      std::cout << "***Invalid input***\n";
    }
  }

  return processVec;
}

#endif