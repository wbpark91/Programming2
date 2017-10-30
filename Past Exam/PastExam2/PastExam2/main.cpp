#include <iostream>
#include "exam.h"

int main() {
    howManyMultiples(3);
    
    std::cout << "Probability = " << waitingTime(20, 30) << std::endl;
    
    Pension pen(10, 10);
    double r = 0.01;
    for (int i = 0; i < 3; ++i) {
        std::cout << "Amount (" << r << ") = " << pen.calcAmount(r) << std::endl;
        r += 0.01;
    }
    return 0;
}
