#include "Employees.hpp"
#include "RandomNameGenerator.hpp"

Employee::Employee() : name{getRandomName()} {}

std::string Employee::print() {
  static const std::string auto_tab{"                    "};
  std::stringstream stream;
  stream << name << auto_tab.substr(name.size()) << "| ";
  return stream.str();
}

Engineer::Engineer() : faculty{getRandomFaculty()} {}

std::string Engineer::print() {
  std::stringstream stream;
  stream << Employee::print() << faculty << std::endl;
  return stream.str();
}

Storeman::Storeman() {
  forklift_licence =
      getRandomBoolean(statutorily::FORKLIFT_LICENSE_PROBABILITY);
}

std::string Storeman::print() {
  std::stringstream stream;
  stream << Employee::print() << dont[(size_t)forklift_licence] << std::endl;
  return stream.str();
}

Marketer::Marketer() {
  no_followers = (unsigned int)std::clamp(
      getRandomDouble(0, statutorily::MAX_NO_FOLLOWERS), 0.,
      statutorily::MAX_NO_FOLLOWERS);
}

std::string Marketer::print() {
  std::stringstream stream;
  stream << Employee::print() << no_followers << std::endl;
  return stream.str();
}

Worker::Worker() {
  foot_size =
      std::round(10. * std::clamp(getRandomDouble(statutorily::MIN_FOOT_SIZE,
                                                  statutorily::MAX_FOOT_SIZE),
                                  statutorily::MIN_FOOT_SIZE,
                                  statutorily::MAX_FOOT_SIZE)) /
      10.;
}

std::string Worker::print() {
  std::stringstream stream;
  stream << Employee::print() << foot_size << std::endl;
  return stream.str();
}

void EmployeesArray::pushBack(Employee_t employee) {
  if (statutorily::MAX_NO_EMPLOYEES <= no_employees + 1) {
    _Xran();
  }
  _Elems[no_employees++] = employee;
  no_employees_with_position[employee.index()]++;
}

size_t EmployeesArray::size() const { return no_employees; }

size_t EmployeesArray::getNoEmplyoeesWithPosition(size_t id) const {
  return no_employees_with_position[id];
}

Employee_t EmployeesArray::operator[](size_t i) const { return _Elems[i]; }