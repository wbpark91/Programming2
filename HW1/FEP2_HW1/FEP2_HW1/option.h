#ifndef option_h
#define option_h
#include "gbmprocess.h"
#include "date.h"
#include "payoff.h"
enum OptionType { Call = 1, Put = -1 };

class Option {
public:
    Option() { }
    Option(Option& opt);
    Option(Date expiration, double strike, OptionType type) :
    expiration_(expiration), strike_(strike), type_(type) { }
    void setProcess(GBMProcess p);
    void setEvalDate(Date d);
    virtual double mcprice(unsigned int numOfSimulation);
    virtual double bntprice(unsigned int nsteps);
    virtual double price() = 0;
    virtual double delta();
    virtual double gamma();
    virtual double vega();
    virtual ~Option() {
        delete payoff_;
    }
    
protected:
    double getd1();
    double getd2();
    
    Date expiration_;
    Date evalDate_;
    double strike_;
    OptionType type_;
    GBMProcess p_;
    double s_, r_, q_, t_, sigma_;
    Payoff* payoff_;
};

#endif /* option_h */
