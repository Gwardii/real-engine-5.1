#pragma once

#include "BalancingAct.hpp"
#include <cmath>
#include <numbers>

class Credit {
private:
  double value;
  double base_instalment;
  double interest;
  unsigned int deadline;

public:
  Credit(double value, unsigned int deadline);
  double payOffInstalment(bool &is_paid_off);
  double const getValue() const;
};
