#include "option.h"
#include <cmath>

Option::Option(Option& inst)
: expiration_(inst.expiration_), strike_(inst.strike_), type_(inst.type_) {
    setEvalDate(inst.evalDate_);
    setProcess(inst.p_);
}

void Option::setEvalDate(Date d) {
    evalDate_ = d;
    t_ = daysBetween(evalDate_, expiration_) / 365.0;
}

void Option::setProcess(GBMProcess p) {
    p_ = p;
    s_ = p.getSpot();
    r_ = p.getRf().rate(expiration_);
    q_ = p.getDiv().rate(expiration_);
    sigma_ = p.getVol();
}

double Option::getd1() {
    return (log(s_ / strike_) + (r_ - q_ + 0.5*sigma_*sigma_)*t_) / (sigma_*sqrt(t_));
}

double Option::getd2() {
    return getd1() - sigma_*sqrt(t_);
}

double Option::delta() {
    s_ = p_.getSpot() * 1.01;
    double p1 = price();
    s_ = p_.getSpot() * 0.99;
    double p2 = price();
    s_ = p_.getSpot();
    return (p1 - p2) / (0.02 * s_);
}

double Option::gamma() {
    double p2 = price();
    s_ = p_.getSpot() * 1.01;
    double p1 = price();
    s_ = p_.getSpot() * 0.99;
    double p3 = price();
    s_ = p_.getSpot();
    return (p1 - 2*p2 + p3) / (0.01 * s_) / (0.01 * s_);
}

double Option::vega() {
    sigma_ = p_.getVol() + 0.01;
    double p1 = price();
    sigma_ = p_.getVol() - 0.01;
    double p2 = price();
    sigma_ = p_.getVol();
    return (p1 - p2) / 0.02;
}
