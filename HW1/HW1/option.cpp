#include "option.h"
#include <cmath>
#include <vector>
#include <random>

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

double Option::bntprice(unsigned int nsteps) {
    double dt = t_ / nsteps;
    double u = exp(sigma_*sqrt(dt));
    double d = 1 / u;
    double p = (exp((r_ - q_)*dt) - d) / (u - d);
    double df = exp(-r_*dt);
    
    std::vector<double> v(nsteps + 1, 0.0);
    for (int j = 0; j <= nsteps; ++j) {
        double st = s_*pow(u, nsteps - j)*pow(d, j);
        v[j] = (*payoff_)(st);  //MAX(type_*(st - strike_), 0)
    }
    
    for (int i = nsteps - 1; i >= 0; --i) {
        for (int j = 0; j <= i; ++j)
            v[j] = df*(v[j] * p + v[j + 1] * (1 - p));
    }
    return v[0];
}

double Option::mcprice(unsigned int numOfSimulation) {
    double sumOfPayoff = 0;
    double df = exp(-r_*t_);
    std::mt19937_64 gen;
    std::normal_distribution<double> engine(0.0, 1.0);
    gen.seed(std::random_device{}());
    double es = s_*exp((r_ - q_ - 0.5*sigma_*sigma_)*t_);
    double diffusion = sigma_*sqrt(t_);
    for (unsigned int i = 0; i < numOfSimulation; ++i) {
        double e = engine(gen);
        for (int j = 0; j < 2; ++j) {
            double st = es * exp(diffusion*(1 - j * 2)*e);
            double p = (*payoff_)(st);      //MAX(type_*(st - strike_), 0)
            sumOfPayoff += df * p;
        }
    }
    return sumOfPayoff / numOfSimulation / 2.0;
}
