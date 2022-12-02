#include "Company.hpp"

Company::Company() : account_balance{statutorily::INITIAL_BALANCE} {
  employees.pushBack(Engineer());
  employees.pushBack(Storeman());
  employees.pushBack(Marketer());
  employees.pushBack(Worker());
}

Company::~Company() {}

void Company::printEmployees() const {
  static const std::string separator =
      "-----------------------------------------------------------------"
      "-----------------\n";
  std::stringstream employees_streams[4];

  size_t end = employees.size();
  for (size_t i = 0; i < end; i++) {
    std::visit([&stream = employees_streams, id = employees[i].index()](
                   auto &&arg) { stream[id] << arg.print(); },
               employees[i]);
  }
  std::cout << separator << separator;
  std::cout << "Employees Census\t "
            << "Number of all employees: " << employees.size() << std::endl;
  std::cout << separator << separator;

  std::cout << "Engineers\t Number of engineers: "
            << employees.getNoEmplyoeesWithPosition(0)
            << "\t\t Salary per capita:" << statutorily::ENGINEER_SALARY
            << std::endl;
  std::cout << separator;
  std::cout << "Name\t\t    | Faculty of" << std::endl;
  std::cout << employees_streams[0].str();
  std::cout << separator << separator;

  std::cout << "Storemen\t Number of storemen: "
            << employees.getNoEmplyoeesWithPosition(1)
            << "\t\t Salary per capita:" << statutorily::STOREMAN_SALARY
            << std::endl;
  std::cout << separator;
  std::cout << "Name\t\t    | Forkilift license" << std::endl;
  std::cout << employees_streams[1].str();
  std::cout << separator << separator;

  std::cout << "Marketers\t Number of marketers: "
            << employees.getNoEmplyoeesWithPosition(2)
            << "\t\t Salary per capita:" << statutorily::MARKETER_SALARY
            << std::endl;
  std::cout << separator;
  std::cout << "Name\t\t    | Number of followers" << std::endl;
  std::cout << employees_streams[2].str();
  std::cout << separator << separator;

  std::cout << "Workers\t\t Number of marketers: "
            << employees.getNoEmplyoeesWithPosition(3)
            << "\t\t Salary per capita:" << statutorily::WORKER_SALARY
            << std::endl;
  std::cout << separator;
  std::cout << "Name\t\t    | Foot size" << std::endl;
  std::cout << employees_streams[3].str();
  std::cout << separator << separator;

  std::cout << std::endl << std::endl;
}

void Company::takeOutCredit(double value, unsigned int deadline) {
  credits.push_back(std::make_unique<Credit>(value, deadline));
}