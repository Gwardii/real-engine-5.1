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

void Company::paySalaries() {
  account_balance -=
      statutorily::ENGINEER_SALARY * employees.getNoEmplyoeesWithPosition(0) +
      statutorily::STOREMAN_SALARY * employees.getNoEmplyoeesWithPosition(1) +
      statutorily::MARKETER_SALARY * employees.getNoEmplyoeesWithPosition(2) +
      statutorily::WORKER_SALARY * employees.getNoEmplyoeesWithPosition(3);
}

void Company::getIncome() {
  products_in_store +=
      statutorily::CR * employees.getNoEmplyoeesWithPosition(3);
  long long store_capacity =
      statutorily::CMag * employees.getNoEmplyoeesWithPosition(1);
  products_in_store =
      (products_in_store < store_capacity) ? products_in_store : store_capacity;
  long long demand =
      statutorily::CMkt * employees.getNoEmplyoeesWithPosition(2);
  long long sold_products =
      (demand < products_in_store) ? demand : products_in_store;
  products_in_store -= sold_products;
  double income =
      statutorily::CI * sold_products * employees.getNoEmplyoeesWithPosition(0);
  account_balance += income;
  income_history.push_back(income);
}

void Company::payOffCredits() {
  bool is_paid_off;
  for (std::list<std::unique_ptr<Credit>>::iterator it = credits.begin();
       it != credits.end();) {
    account_balance -= (*it)->payOffInstalment(is_paid_off);
    if (is_paid_off) {
      it = credits.erase(it);
    } else {
      ++it;
    }
  }
}

const double Company::getAccountBalance() const { return account_balance; }
const double Company::getCompanyValue() const {
  if (income_history.empty()) {
    return 0;
  }
  if (income_history.size() > statutorily::N) {
    return std::accumulate(income_history.end() - statutorily::N,
                           income_history.end(), 0) /
           statutorily::N;
  }
  return std::accumulate(income_history.begin(), income_history.end(), 0) /
         income_history.size();
}

const double Company::getSumOfAllCredits() const {
  return std::accumulate(credits.begin(), credits.end(), 0.,
                         [](double x, const std::unique_ptr<Credit> &y) {
                           return x + y->getValue();
                         });
}