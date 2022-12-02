#pragma once

#include "BalancingAct.hpp"
#include "Credit.hpp"
#include "Employees.hpp"
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
  void takeCredit(double value, unsigned int deadline);
  void hireEmployee();
  void payOffCredit();
  const double getAccountBalance();
  const double getCompanyValue();
};