#include <iostream>
#include "date.h"
#include "yield_termstructure.h"
#include "plainvanilla_option.h"
#include "binary_option.h"
#include "option_portfolio.h"

int main() {
    std::vector<Date> date;
    for (int i = 9; i <= 12; ++i) {
        date.push_back(Date(2017, i, 30));
    }
    for (int i = 1; i <= 4; ++i) {
        date.push_back(Date(2018, i, 30));
    }
    Date evalDate = date[0];
    
    std::vector<double> rate = {0.015, 0.015, 0.017, 0.0185, 0.0195, 0.0205, 0.0213, 0.0220};
    std::vector<double> div = {0, 0, 0, 0.03, 0.03, 0.03, 0.04, 0.04};
    YieldTermStructure terms(date, rate);
    YieldTermStructure divs(date, div);
    GBMProcess mktVar(200, terms, divs, 0.15);
    
    PlainVanillaOption inst1(Date(2018, 1, 10), 200, Call);
    BinaryOption inst2(Date(2017, 11 ,25), 200, Call);
    
    std::vector<Option*> vec = {&inst1, &inst2};
    std::vector<Position> pos = {Long, Short};
    std::vector<int> quant = {2, 10};
    
    OptionPortfolio port(vec, pos, quant);
    port.setEvalDate(evalDate);
    port.setProcess(mktVar);
    std::cout << port.price() << std::endl;
    std::cout << port.delta() << std::endl;
    std::cout << port.gamma() << std::endl;
    std::cout << port.vega() << std::endl;
    return 0;
}
