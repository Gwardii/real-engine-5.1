#include "Company.hpp"
#include <iostream>

int main() {
  std::cout << "Hello World!" << std::endl;
  Worker x = Worker();
  x.print();
  Credit c = Credit(800, 12);
}
