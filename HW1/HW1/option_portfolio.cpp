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
    std::cout << "Information of Individual Options" << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << "No." << "\t" << "Price" << "\t\t" << "Delta";
    std::cout << "\t\t" << "Gamma" << "\t\t" << "Vega" << std::endl;
    for (int i = 0; i < instrument_.size(); ++i) {
        printf("%d \t", i+1);
        printf("%.5f \t", instrument_[i] -> price());
        printf("%.5f \t", instrument_[i] -> delta());
        printf("%.5f \t", instrument_[i] -> gamma());
        printf("%.5f \t", instrument_[i] -> vega());
        std::cout << std::endl;
    }
    std::cout << "==========================" << std::endl;
    std::cout << "Portfolio Value Evaluation" << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Price: " << calc(&Option::price) << std::endl;
    std::cout << "Delta: " << calc(&Option::delta) << std::endl;
    std::cout << "Gamma: " << calc(&Option::gamma) << std::endl;
    std::cout << "Vega: " << calc(&Option::vega) << std::endl;
    std::cout << "==========================" << std::endl;
}
