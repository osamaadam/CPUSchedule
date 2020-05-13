#include "readFile.hpp"
#include <iostream>

int main()
{
  std::cout << readFile("input.txt")[1].arrivalTime << "\n";
}