#pragma once

#include "BalancingAct.hpp"
#include "Company.hpp"
#include <iostream>

class MonopolySinglePlayer {
private:
  unsigned int month{1};
  unsigned int status{0};
  std::unique_ptr<Company> company{std::make_unique<Company>()};
  bool playerAction();
  void printHelp();
  void printInstruction();
  void tick();

public:
  MonopolySinglePlayer();
  void launch();
};