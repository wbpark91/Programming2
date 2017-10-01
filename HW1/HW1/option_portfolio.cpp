#include "option_portfolio.h"
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

double OptionPortfolio::price() {
    double price = 0;
    for (int i = 0; i < instrument_.size(); ++i) {
        price += instrument_[i] -> price() * position_[i] * quantity_[i];
    }
    return price;
}

double OptionPortfolio::delta() {
    double delta = 0;
    for (int i = 0; i < instrument_.size(); ++i) {
        delta += instrument_[i] -> delta() * position_[i] * quantity_[i];
    }
    return delta;
}

double OptionPortfolio::gamma() {
    double gamma = 0;
    for (int i = 0; i < instrument_.size(); ++i) {
        gamma += instrument_[i] -> gamma() * position_[i] * quantity_[i];
    }
    return gamma;
}

double OptionPortfolio::vega() {
    double vega = 0;
    for (int i = 0; i < instrument_.size(); ++i) {
        vega += instrument_[i] -> vega() * position_[i] * quantity_[i];
    }
    return vega;
}
