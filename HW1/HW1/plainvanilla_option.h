#ifndef plainvanilla_option_h
#define plainvanilla_option_h
#include "date.h"
#include "gbmprocess.h"
#include "option.h"

class PlainVanillaOption : public Option {
public:
    PlainVanillaOption(Date expiration, double strike,
                       OptionType type) : Option(expiration, strike, type) {}
    virtual double price();
    double delta();
    double gamma();
    double vega();
    double impliedVol(double mktPrice, double init = 0.1,
                      double tol = 1e-6);
    
private:
    void setVolatility(double sigma) {
        sigma_ = sigma;
    }
};

#endif /* plainvanillaoption_h */
