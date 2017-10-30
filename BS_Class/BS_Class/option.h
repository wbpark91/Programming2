#ifndef option_h
#define option_h
#include "date.h"
#include "GBMProcess.h"
#include "payoff.h"
enum OptionType { Call = 1, Put = -1 };

class Option {
public:
    Option(Date expiration, double strike, OptionType type) :
    expiration_(expiration), strike_(strike), type_(type) {}
    virtual ~Option() {
        delete payoff_;
    }
    void setProcess(GBMProcess p);
    void setEvalDate(Date d);
    virtual double mcprice(unsigned int numOfSimulation);
    virtual double bntprice(unsigned int nsteps);
    virtual double price() = 0;     // 반드시 virtual이어야 함.
    virtual double vega() { return 1; }
    virtual double impliedVol(double m, double init = 0.1, double tol = 1e-6) { return 10; }
    
    
protected:
    double getd1();
    double getd2();
    
    Date evalDate_;
    Date expiration_;
    double strike_;
    OptionType type_;
    GBMProcess p_;
    double s_, r_, q_, t_, sigma_;
    
    Payoff* payoff_;
};

#endif /* option_h */
