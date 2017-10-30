#ifndef binary_option_h
#define binary_option_h
#include "option.h"
#include "payoff.h"

class BinaryPayoff: public Payoff {
public:
    BinaryPayoff() {}
    BinaryPayoff(double strike, OptionType type) : strike_(strike), type_(type) {}
    virtual ~BinaryPayoff() {}
    double operator()(double s) {
        return type_*(s - strike_) > 0.0 ? 1.0 : 0.0;
    }
private:
    double strike_;
    OptionType type_;
};

class BinaryOption: public Option {
public:
    BinaryOption() { }
    BinaryOption(Date expiration, double strike,
                 OptionType type) : Option(expiration, strike, type) {
        payoff_ = new BinaryPayoff(strike, type);
    }
    BinaryOption(const BinaryOption& inst);
    virtual double price();
};

#endif /* binary_option_h */
