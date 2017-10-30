#ifndef binaryoption_h
#define binaryoption_h
#include "option.h"
#include "payoff.h"

class BinaryPayoff : public Payoff {
public:
    BinaryPayoff(double strike, OptionType type) :
    strike_(strike), type_(type) {}
    double operator()(double s) {               // Payoff class의 operator()를 overriding
        return type_*(s - strike_) > 0.0 ? 1.0 : 0.0;
    }
private:
    double strike_;
    OptionType type_;
};

class BinaryOption : public Option
{
public:
    BinaryOption(Date expiration, double strike, OptionType type) :
    Option(expiration, strike, type) {
        payoff_ = new BinaryPayoff(strike, type);
    }
    virtual double price();
};

#endif /* binaryoption_h */
