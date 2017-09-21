#ifndef plainvanilla_option_h
#define plainvanilla_option_h

#include "date.h"
#include "GBMProcess.h"

enum OptionType { Call = 1, Put = -1 };

class PlainVanillaOption {
public:
    PlainVanillaOption(Date expiration, double strike, OptionType type) : expiration_(expiration), strike_(strike), type_(type) {}
    void setProcess(GBMProcess p) { p_ = p; }       // Class의 객체는 대입연산자(=)에 대한 함수가 있음
    
    double price(Date evalDate);
    double vega(Date evalDate);
    double impliedVol(Date evalDate, double mktPrice,
                      double init = 0.1, double tol = 1e-6);
    
private:
    // private에 멤버 함수 쓸 수 있음. 클래스 안에서만 사용할 수 있는 함수
    double bsprice(double s, double k, double r, double q, double t, double sigma, OptionType type);
    double bsvega(double s,double k, double r, double q,
                  double t,double sigma, OptionType type);
    
    Date expiration_;
    double strike_;
    OptionType type_;
    GBMProcess p_;          // 옵션 생성자에서 Process를 인자로 받지 않기 때문에 GBMProcess에 default 생성자가 있어야 함
};

#endif /* plainvanilla_option_h */
