#include "Employees.hpp"
#include "RandomNameGenerator.hpp"

Employee::Employee() { name = getRandomName(); }

void Employee::print() {
  std::cout << "My name is " << name << "." << std ::endl;
}

Engineer::Engineer() { faculty = getRandomFaculty(); }

void Engineer::print() {
  std::cout << "My name is " << name << " and I have graduated " << faculty
            << "." << std::endl;
}

Storeman::Storeman() {
  forklift_licence =
      getRandomBoolean(statutorily::FORKLIFT_LICENSE_PROBABILITY);
}

void Storeman::print() {
  std::cout << "My name is " << name << " and I " << dont[(int)forklift_licence]
            << "have a forklift license." << std::endl;
}

Marketer::Marketer() {
  no_followers = getRandomInt(0, statutorily::MAX_NO_FOLLOWERS);
}

void Marketer::print() {
  std::cout << "My name is " << name << " and I have " << no_followers
            << " followers." << std::endl;
}

Worker::Worker() {
  foot_size =
      std::round(10. * std::clamp(getRandomDouble(statutorily::MIN_FOOT_SIZE,
                                                  statutorily::MAX_FOOT_SIZE),
                                  statutorily::MIN_FOOT_SIZE,
                                  statutorily::MAX_FOOT_SIZE)) /
      10.;
}

void Worker::print() {
  std::cout << "My name is " << name << " and I have a foot size " << foot_size
            << "." << std::endl;
}