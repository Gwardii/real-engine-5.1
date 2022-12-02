#include "Company.hpp"

Company::Company() : account_balance{statutorily::INITIAL_BALANCE} {
  employees.pushBack(Engineer());
  employees.pushBack(Storeman());
  employees.pushBack(Marketer());
  employees.pushBack(Worker());
}

Company::~Company() {}

void Company::printEmployees() const {
  for (Employee_t employee : employees) {
    std::visit([](auto &&arg) { arg.print(); }, employee);
  }
}