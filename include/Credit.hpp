#pragma once

#include "BalancingAct.hpp"

class Credit {
private:
  double value;
  unsigned int deadline;

public:
  Credit(double value, unsigned int deadline);
  double payOffInstalment();
};
