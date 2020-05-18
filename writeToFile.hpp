#ifndef WRITETOFILE
#define WRITETOFILE

#include <fstream>
#include <iostream>

#include "Process.hpp"

bool writeToFile(std::string filename, std::string content) {
  remove(filename.c_str());
  std::ofstream outputFile;
  outputFile.open(filename);
  outputFile << content;
  outputFile.close();
  return true;
}

#endif