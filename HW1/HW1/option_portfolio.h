#ifndef option_portfolio_h
#define option_portfolio_h
#include "option.h"
#include <vector>

enum Position { Long = 1, Short = -1 };
enum OptionClass { PlainVanilla, Binary };

class OptionPortfolio {
public:
    OptionPortfolio() { }
    OptionPortfolio(std::vector<Option*> instrument,std::vector<Position> position,
                    std::vector<int> quantity) : instrument_(instrument),position_(position), quantity_(quantity) {
        if(!(instrument.size() == position.size() && instrument.size() == quantity.size() &&
             position.size() == quantity.size())) {
            throw std::length_error("Unequal vector length");
        }
    }
    ~OptionPortfolio();
    void setProcess(GBMProcess p);
    void setEvalDate(Date d);
    // price, greek function 주소값을 인자로 받아 포트폴리오의 value, greek을 계산하는 함수
    double calc(double (Option::*func)());
    void printInfo();
private:
    std::vector<Option*> instrument_;
    std::vector<Position> position_;
    std::vector<int> quantity_;
};

#endif /* option_portfolio_h */
