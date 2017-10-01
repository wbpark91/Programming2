#ifndef option_portfolio_h
#define option_portfolio_h
#include "option.h"
#include <vector>

enum Position { Long = 1, Short = -1 };

class OptionPortfolio {
public:
    OptionPortfolio() { }
    OptionPortfolio(std::vector<Option*> instrument,std::vector<Position> position,
                    std::vector<int> quantity) : instrument_(instrument),position_(position), quantity_(quantity) { }
    void setProcess(GBMProcess p);
    void setEvalDate(Date d);
    //double calc(double(Option::*func)());     함수 포인터를 이용, 포트폴리오의 가격, greek 계산 일반화 가능할 것임
    double price();
    double delta();
    double gamma();
    double vega();
private:
    std::vector<Option*> instrument_;
    std::vector<Position> position_;
    std::vector<int> quantity_;
};

#endif /* option_portfolio_h */
