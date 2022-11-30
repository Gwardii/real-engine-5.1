#include "Credit.hpp"

Credit::Credit(double value_, unsigned int deadline_)
    : value{value_}, deadline{deadline_} {}

double Credit::payOffInstalment() { return 2.; }