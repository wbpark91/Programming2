#ifndef plainvanilla_option_h
#define plainvanilla_option_h
#include "date.h"
#include "gbmprocess.h"
#include "option.h"
#include "payoff.h"
#define MAX(x,y) (((x)>(y))?(x):(y))

class PlainVanillaPayoff : public Payoff {
public:
    PlainVanillaPayoff() {}
    PlainVanillaPayoff(double strike, OptionType type) : strike_(strike), type_(type) {}
    virtual ~PlainVanillaPayoff() {}
    virtual double operator()(double s) {
        return type_*MAX(s - strike_, 0.0);
    }
private:
    double strike_;
    OptionType type_;
};

class PlainVanillaOption : public Option {
public:
    PlainVanillaOption(Date expiration, double strike,
                       OptionType type) : Option(expiration, strike, type) {
        payoff_ = new PlainVanillaPayoff(strike, type);
    }
    PlainVanillaOption(const PlainVanillaOption& inst);
    virtual double price();
    virtual double delta();
    virtual double gamma();
    virtual double vega();
    double impliedVol(double mktPrice, double init = 0.1,
                      double tol = 1e-6);
    
private:
    void setVolatility(double sigma) {
        sigma_ = sigma;
    }
};

#endif /* plainvanillaoption_h */
