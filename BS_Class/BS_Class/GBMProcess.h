#ifndef GBMProcess_h
#define GBMProcess_h

class GBMProcess
{
public:
    GBMProcess() {}     // 반드시 있어야 PlainvanillaOption class가 구현됨
    GBMProcess(double spot, double rf, double div, double vol) :
        spot_(spot), rf_(rf), div_(div), vol_(vol) {}
    double getSpot() { return spot_; }
    double getRf() { return rf_; }
    double getDiv() { return div_; }
    double getVol() { return vol_; }
    ~GBMProcess() {};
private:
    double spot_, rf_, div_, vol_;
};


#endif /* GBMProcess_h */
