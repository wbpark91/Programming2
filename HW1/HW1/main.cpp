#include <iostream>
#include <string>
#include "date.h"
#include "yield_termstructure.h"
#include "plainvanilla_option.h"
#include "binary_option.h"
#include "option_portfolio.h"

int main() {
    
    try {
        std::vector<Date> date;
        for (int i = 9; i <= 12; ++i) {
            date.push_back(Date(2017, i, 30));
        }
        date.push_back(Date(2018, 1, 30));
        date.push_back(Date(2018, 2, 28));
        for (int i = 3; i <= 4; ++i) {
            date.push_back(Date(2018, i, 30));
        }
        Date evalDate = date[0];
        
        std::vector<double> rate = {0.015, 0.015, 0.017, 0.0185, 0.0195, 0.0205, 0.0213, 0.0220};
        std::vector<double> div = {0, 0, 0, 0.03, 0.03, 0.03, 0.04, 0.04};
        std::vector<Date> expiration = {Date(2018, 1,10), Date(2017, 12, 12), Date(2018, 3, 15), Date(2017, 12, 12), Date(2018, 3, 15),
            Date(2018, 1, 10), Date(2017, 11, 25), Date(2018, 3, 20), Date(2018, 2, 18), Date(2017, 12, 19), Date(2018, 1, 15)
        };
        std::vector<double> strike = {200, 205, 195, 200, 210, 190, 200, 220, 200, 210, 190};
        std::vector<OptionType> type = {Call, Call, Call, Put, Put, Put, Call, Call, Put, Put, Put};
        std::vector<OptionClass> optClass = {PlainVanilla, PlainVanilla, PlainVanilla, PlainVanilla, PlainVanilla, PlainVanilla, Binary, Binary, Binary, Binary, Binary};
        
        YieldTermStructure terms(date, rate);
        YieldTermStructure divs(date, div);
        GBMProcess mktVar(200, terms, divs, 0.15);
        GBMProcess mktVar1(220, terms, divs, 0.15);
        GBMProcess mktVar2(180, terms, divs, 0.15);
        
        std::vector<Option*> vec;
        for (int i = 0; i < optClass.size(); ++i) {
            if (optClass[i] == PlainVanilla) {
                vec.push_back(new PlainVanillaOption(expiration[i], strike[i], type[i]));
            }
            else if (optClass[i] == Binary) {
                vec.push_back(new BinaryOption(expiration[i], strike[i], type[i]));
            }
            else {
                std::cerr << "Invalid option class" << std::endl;
                return 1;
            }
        }
        
        std::vector<Position> pos = {Long, Short, Long, Short, Short, Long,
            Short, Long, Short, Long, Long};
        std::vector<int> quant = {2, 1, 3, 2, 1, 2, 10, 25, 10, 10, 20};
        
        OptionPortfolio port(vec, pos, quant);
        port.setEvalDate(evalDate);
        port.setProcess(mktVar);
        
        std::cout << "Underlying Price: " << mktVar.getSpot() << std::endl;
        std::cout << std::string(35, '-') << std::endl;
        port.printInfo();
        std::cout << std::endl;
        
        port.setProcess(mktVar1);
        std::cout << "Underlying Price: " << mktVar1.getSpot() << std::endl;
        std::cout << std::string(35, '-') << std::endl;
        port.printInfo();
        std::cout << std::endl;
        
        port.setProcess(mktVar2);
        std::cout << "Underlying Price: " << mktVar2.getSpot() << std::endl;
        std::cout << std::string(35, '-') << std::endl;
        port.printInfo();
        return 0;
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch(...) {
        std::cerr << "Unknown error" << std::endl;
        return 1;
    }
}
