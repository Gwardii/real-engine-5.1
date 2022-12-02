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
  std::string print();
};
class Engineer : Employee {
private:
  std::string faculty;

public:
  Engineer();
  std::string print();
};
class Storeman : Employee {
private:
  static constexpr std::array dont{"No", "Yes"};
  bool forklift_licence;

public:
  Storeman();
  std::string print();
};
class Marketer : Employee {
private:
  int no_followers;

public:
  Marketer();
  std::string print();
};
class Worker : Employee {
private:
  double foot_size;

public:
  Worker();
  std::string print();
};

using Employee_t = std::variant<Engineer, Storeman, Marketer, Worker>;

class EmployeesArray : std::array<Employee_t, statutorily::MAX_NO_EMPLOYEES> {
private:
  size_t no_employees{0};
  size_t no_employees_with_position[4]{0, 0, 0, 0};

public:
  void pushBack(Employee_t employee);
  size_t size() const;
  Employee_t operator[](size_t i) const;
  size_t getNoEmplyoeesWithPosition(size_t id) const;
};
