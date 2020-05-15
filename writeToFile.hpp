#ifndef WRITETOFILE
#define WRITETOFILE

#include "Process.hpp"
#include <fstream>
#include <iostream>

bool writeToFile(std::string filename, std::string content)
{
  std::ofstream outputFile;
  outputFile.open(filename);
  outputFile << content;
  outputFile.close();
  return true;
}

#endif