#pragma once

#include "BalancingAct.hpp"
#include "Company.hpp"
#include <iostream>

class MonopolySinglePlayer {
private:
  unsigned int month{1};
  bool status{true};
  std::unique_ptr<Company> company{std::make_unique<Company>()};
  bool playerAction();
  void printHelp();
  void printInstruction();
  void printCompanyStatus();

public:
  MonopolySinglePlayer();
  void launch();
};