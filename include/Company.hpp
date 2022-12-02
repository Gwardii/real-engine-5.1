#pragma once

#include "BalancingAct.hpp"
#include "Credit.hpp"
#include "Employees.hpp"
#include <sstream>
#include <vector>

class Company {
private:
  double account_balance;
  std::vector<std::unique_ptr<Credit>> credits;
  EmployeesArray employees;
  std::vector<double> income_history;

  const double getIncome();

public:
  Company();
  ~Company();
  void printEmployees() const;
  void takeOutCredit(double value, unsigned int deadline);
  template <class T> void hireEmployee() { employees.pushBack(T()); }
  void payOffCredit();
  const double getAccountBalance();
  const double getCompanyValue();
};