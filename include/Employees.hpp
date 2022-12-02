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
  void print();
};
class Engineer : Employee {
private:
  std::string faculty;

public:
  Engineer();
  void print();
};
class Storeman : Employee {
private:
  static constexpr std::array dont{"don't ", ""};
  bool forklift_licence;

public:
  Storeman();
  void print();
};
class Marketer : Employee {
private:
  int no_followers;

public:
  Marketer();
  void print();
};
class Worker : Employee {
private:
  double foot_size;

public:
  Worker();
  void print();
};

using Employee_t = std::variant<Engineer, Storeman, Marketer, Worker>;

class EmployeesArray
    : public std::array<Employee_t, statutorily::MAX_NO_EMPLOYEES> {
private:
  size_t no_employees{0};

public:
  using iterator =
      std::_Array_iterator<Employee_t, statutorily::MAX_NO_EMPLOYEES>;
  using const_iterator =
      std::_Array_const_iterator<Employee_t, statutorily::MAX_NO_EMPLOYEES>;
  _NODISCARD _CONSTEXPR17 iterator end() noexcept;
  _NODISCARD _CONSTEXPR17 const_iterator end() const noexcept;
  void pushBack(Employee_t employee);
  size_t size();
};
