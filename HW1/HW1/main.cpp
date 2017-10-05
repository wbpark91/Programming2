#include <iostream>
#include <string>
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
    GBMProcess mktVar1(220, terms, divs, 0.15);
    GBMProcess mktVar2(180, terms, divs, 0.15);
    
    PlainVanillaOption inst1(Date(2018, 1, 10), 200, Call);
    PlainVanillaOption inst2(Date(2017, 12 ,12), 205, Call);
    PlainVanillaOption inst3(Date(2018, 3, 15), 195, Call);
    PlainVanillaOption inst4(Date(2017, 12, 12), 200, Put);
    PlainVanillaOption inst5(Date(2018, 3, 15), 210, Put);
    PlainVanillaOption inst6(Date(2018, 1, 10), 190, Put);
    BinaryOption inst7(Date(2017, 11, 25), 200, Call);
    BinaryOption inst8(Date(2018, 3, 20), 220, Call);
    BinaryOption inst9(Date(2018, 2, 18), 200, Put);
    BinaryOption inst10(Date(2017, 12, 19), 210, Put);
    BinaryOption inst11(Date(2018, 1, 15), 190, Put);
    std::vector<Option*> vec = {&inst1, &inst2, &inst3, &inst4, &inst5, &inst6, &inst7, &inst8,
        &inst9, &inst10, &inst11};
    std::vector<Position> pos = {Long, Short, Long, Short, Short, Long,
        Short, Long, Short, Long, Long};
    std::vector<int> quant = {2, 1, 3, 2, 1, 2, 10, 25, 10, 10, 20};
    
    OptionPortfolio port(vec, pos, quant);
    port.setEvalDate(evalDate);
    port.setProcess(mktVar);
    std::cout << "Underlying Price: " << mktVar.getSpot() << std::endl;
    std::cout << "===================" << std::endl;
    port.printInfo();
    std::cout << std::endl;
    
    port.setProcess(mktVar1);
    std::cout << "Underlying Price: " << mktVar1.getSpot() << std::endl;
    std::cout << "===================" << std::endl;
    port.printInfo();
    std::cout << std::endl;
    
    port.setProcess(mktVar2);
    std::cout << "Underlying Price: " << mktVar2.getSpot() << std::endl;
    std::cout << "===================" << std::endl;
    port.printInfo();
    return 0;
}
