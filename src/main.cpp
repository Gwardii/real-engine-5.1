#include "Company.hpp"
#include <iostream>

int main() {
  std::cout << "Hello World!" << std::endl;
  Credit c = Credit(800, 12);
  Company com = Company{};
  // com.hireEmployee<int>();
  com.hireEmployee<Engineer>();
  com.printEmployees();
}
