#include <iostream>
#include "date.h"
#include "yield_termstructure.h"
#include "plainvanilla_option.h"

int main() {
    std::vector<Date> date;
    for (int i = 9; i <= 12; ++i) {
        date.push_back(Date(2017, i, 30));
    }
    for (int i = 1; i <= 4; ++i) {
        date.push_back(Date(2018, i, 30));
    }
    
    std::vector<double> rate = {0.015, 0.015, 0.017, 0.0185, 0.0195, 0.0205, 0.0213, 0.0220};
    
    YieldTermStructure terms(date, rate);
    Date evalDate(2017, 12, 30);
    
    std::cout << daysBetween(Date(2017,11,30), Date(2017,12,20)) << std::endl;
    std::cout << daysBetween(Date(2017,12,20), Date(2017,12,30)) << std::endl;
    
    std::cout << terms.rate(evalDate) << std::endl;
    std::cout << terms.discount(Date(2017, 10, 30)) << std::endl;
    std::cout << terms.discount(Date(2017, 11, 30)) << std::endl;
    std::cout << terms.discount(Date(2017, 12, 30)) << std::endl;
    std::cout << terms.forwardRate(Date(2017, 11, 30), Date(2017, 12, 30)) << std::endl;
    return 0;
}
