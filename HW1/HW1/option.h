#ifndef option_h
#define option_h
#include "gbmprocess.h"
#include "date.h"
enum OptionType { Call = 1, Put = -1 };

class Option {
public:
    Option() { }
    Option(Option& opt);
    Option(Date expiration, double strike, OptionType type) :
    expiration_(expiration), strike_(strike), type_(type) { }
    void setProcess(GBMProcess p);
    void setEvalDate(Date d);
    virtual double price() = 0;
    double delta();
    double gamma();
    double vega();
    virtual ~Option() { }
    
protected:
    double getd1();
    double getd2();
    
    Date expiration_;
    Date evalDate_;
    double strike_;
    OptionType type_;
    GBMProcess p_;
    double s_, r_, q_, t_, sigma_;
};

#endif /* option_h */
