#include "binary_option.h"
#include "normal.h"
#include <cmath>

BinaryOption::BinaryOption(const BinaryOption& inst) : Option(inst.expiration_, inst.strike_, inst.type_) {
    payoff_ = new BinaryPayoff(inst.strike_, inst.type_);
}

double BinaryOption::price() {
    double d2 = getd2();
    double nd2 = normcdf(type_ * d2);
    return exp(-r_ * t_) * nd2;
}
