#ifndef gbmprocess_h
#define gbmprocess_h
#include "yield_termstructure.h"

class GBMProcess {
public:
    GBMProcess() {}
    GBMProcess(double spot, YieldTermStructure rf, YieldTermStructure div, double vol)
    :spot_(spot), rf_(rf), div_(div), vol_(vol) {}
    double getSpot() { return spot_; }
    YieldTermStructure getRf() { return rf_; }
    YieldTermStructure getDiv() { return div_; }
    double getVol() { return vol_; }
    ~GBMProcess() {}
private:
    YieldTermStructure rf_, div_;
    double spot_, vol_;
};

#endif /* gbmprocess_h */
