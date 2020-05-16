#ifndef PROMPT
#define PROMPT

#include <iostream>

struct Choice
{
  int mode, quanta = 0;
};

Choice prompt()
{
  Choice choice;

  std::cout << "Mode of operation:\n"
            << "0: First Come First Served (FCFS)\n"
            << "1: Round Robin\n";

  std::cin >> choice.mode;

  switch (choice.mode)
  {
  case 0:
    std::cout << "You chose FCFS.\n";
    break;
  case 1:
    std::cout << "You chose round robin.\n";
    std::cout << "Please enter the time quanta for each process.\n";
    std::cin >> choice.quanta;
    while (std::cin.fail() || !choice.quanta)
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Sorry, invalid input.\n"
                << "Please, enter an integer.\n";
      std::cin >> choice.quanta;
    }
    break;
  default:
    std::cout << "Invalid input, please try again!\n";
    choice = prompt();
    break;
  }

  return choice;
}

#endif