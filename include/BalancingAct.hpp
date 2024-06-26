#pragma once

namespace statutorily {
const double WIN_CONDITION = 1e6;
const size_t MAX_NO_EMPLOYEES = 5000;
const size_t MAX_NO_CREDITS = 5000;
const double MAX_CREDIT = 1e4;

// the effectiveness of employees
const double CI = 1000;
const int CMag = 40;
const int CMkt = 60;
const int CR = 70;

// employees' salaries
const double ENGINEER_SALARY = 1e4;
const double STOREMAN_SALARY = 4e3;
const double MARKETER_SALARY = 6e3;
const double WORKER_SALARY = 4e3;

const unsigned int N = 3; // number of months to calculate an average income

const double M = 5;
const unsigned int X = 12;    // credit deadline
const double MAX_RRSO = 0.2;  // 20%
const double MIN_RRSO = 0.05; // 5%
const double INITIAL_BALANCE = 5e4;

const double FORKLIFT_LICENSE_PROBABILITY = 0.5;
const double MAX_NO_FOLLOWERS = 5000000;
const double MIN_FOOT_SIZE = 36;
const double MAX_FOOT_SIZE = 48;
} // namespace statutorily