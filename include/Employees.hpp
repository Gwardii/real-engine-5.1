#pragma once

#include "BalancingAct.hpp"
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <variant>

class Employee {
protected:
  std::string name;

public:
  Employee();
  virtual void print();
};
class Engineer : Employee {
private:
  std::string faculty;

public:
  Engineer();
  void print() override;
};
class Storeman : Employee {
private:
  static constexpr std::array dont{"don't ", ""};
  bool forklift_licence;

public:
  Storeman();
  void print() override;
};
class Marketer : Employee {
private:
  int no_followers;

public:
  Marketer();
  void print() override;
};
class Worker : Employee {
private:
  double foot_size;

public:
  Worker();
  void print() override;
};

using Employee_t = std::variant<Engineer, Storeman, Marketer, Worker>;