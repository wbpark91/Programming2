#include <iostream>
#include "plainvanilla_option.h"
#include "binaryoption.h"
#include "barrieroption.h"
#include <vector>

void print_option(Option* x, double p) {
    std::cout << "price = " << x->price() << std::endl;
    std::cout << "mc price = " << x->mcprice(100000) << std::endl;
    std::cout << "bnt price = " << x->bntprice(1000) << std::endl;
    std::cout << std::string(30, '-') << std::endl;
}

// 포인터가 빠른 이유: 포인터를 쓰지 않으면 로컬 변수를 사용하는데, 복사하고 삭제하는 과정을 반복하기 때문에 포인터가 더 속도가 빠름

int main() {
    Date evalDate(2017, 9, 1);
    Date mat(2017, 10, 31);
    double spot = 100, stk = 100, rf = 0.01, div = 0.01, vol = 0.2;
    OptionType type = Call;
    GBMProcess process(spot, rf, div, vol);
    
    std::vector<double> mktprice = { 3.2, 4.2, 1.4 };
    std::vector<Option*> inst;
    inst.push_back(new BinaryOption(mat, stk, type));
    inst.push_back(new PlainVanillaOption(mat, stk, type));
    //inst.push_back(new BarrierOption(mat, stk, type, 90, DownOut));
    
    for (int i = 0; i < inst.size(); ++i) {
        inst[i]->setProcess(process);
        inst[i]->setEvalDate(evalDate);
        print_option(inst[i], mktprice[i]);
    }
    
    for (int i = 0; i < inst.size(); ++i)
        delete inst[i];
    
    BinaryPayoff x(stk, type);
    BinaryPayoff x1 = BinaryPayoff(stk, type);
    
    BinaryPayoff y(x);  // 복사 생성자
    BinaryPayoff z(100, Call);
    z = x;              // 대입 연산자
     
    return 0;
}
