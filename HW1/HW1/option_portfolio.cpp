#include "option_portfolio.h"
#include <iostream>
double OptionPortfolio::calc(double (Option::*func)()) {
    double value = 0;
    for (int i = 0; i < instrument_.size(); ++i) {
        value += (instrument_[i] ->* func)() * position_[i] * quantity_[i];
    }
    return value;
}

void OptionPortfolio::setProcess(GBMProcess p) {
    for (int i = 0; i < instrument_.size(); ++i) {
        instrument_[i] -> setProcess(p);
    }
}

void OptionPortfolio::setEvalDate(Date d) {
    for (int i = 0; i < instrument_.size(); ++i) {
        instrument_[i] -> setEvalDate(d);
    }
}

void OptionPortfolio::printInfo() {
    std::cout << "Price: " << calc(&Option::price) << std::endl;
    std::cout << "Delta: " << calc(&Option::delta) << std::endl;
    std::cout << "Gamma: " << calc(&Option::gamma) << std::endl;
    std::cout << "Vega: " << calc(&Option::vega) << std::endl;
}
