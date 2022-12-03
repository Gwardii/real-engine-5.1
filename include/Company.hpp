#pragma once

#include "BalancingAct.hpp"
#include "Credit.hpp"
#include "Employees.hpp"
#include <list>
#include <numeric>
#include <sstream>
#include <vector>

class Company {
private:
  double account_balance;
  std::list<std::unique_ptr<Credit>> credits;
  EmployeesArray employees;
  std::vector<double> income_history;
  long long products_in_store{0};

public:
  Company();
  ~Company();
  void printEmployees() const;
  void takeOutCredit(double value, unsigned int deadline);
  template <class T> void hireEmployee() { employees.pushBack(T()); }
  void paySalaries();
  void payOffCredits();
  void getIncome();
  const double getAccountBalance() const;
  const double getCompanyValue() const;
  const double getSumOfAllCredits() const;
};