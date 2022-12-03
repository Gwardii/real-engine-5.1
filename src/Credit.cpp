#include "Credit.hpp"

Credit::Credit(double value_, unsigned int deadline_)
    : value{value_}, deadline{deadline_} {
  // Interests are computed as an expotential function y=a(exp(b*time + c) -1)
  // such as annual interests for a 1 month credit are equal to MIN_RRSO and
  // annual interests for a X month credit are equal to MAX_RRSO.
  base_instalment = std::round(value / deadline * 100.) / 100.;
  double b = 1. / (statutorily::X - 1) *
             std::log(statutorily::MAX_RRSO / statutorily::MIN_RRSO / 2. + 0.5);
  double c = std::log(2) - b;
  interest = statutorily::MIN_RRSO * (std::exp(b * deadline + c) - 1);
}

double Credit::payOffInstalment(bool &is_paid_off) {
  double instalment;
  if (--deadline > 0) {
    instalment = base_instalment + value * interest / 12.;
    value = value - base_instalment;
    is_paid_off = false;
    return instalment;
  }
  instalment = value;
  is_paid_off = true;
  return instalment;
}

double const Credit::getValue() const { return value; }