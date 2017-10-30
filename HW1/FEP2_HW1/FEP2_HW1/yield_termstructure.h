#ifndef yield_termstructure_h
#define yield_termstructure_h
#include <vector>
#include <cmath>
#include "date.h"

class YieldTermStructure {
public:
    YieldTermStructure() {}
    YieldTermStructure(std::vector<Date> dates, std::vector<double> rates)
    :dates_(dates), rates_(rates) { }
    double rate(Date d);
    double discount(Date d);
    double forwardRate(Date d1, Date d2);
private:
    std::vector<int> findBetweenDates(Date d);    // 인접한 두 날짜의 index를 찾아주는 함수
    std::vector<Date> dates_;
    std::vector<double> rates_;
};

#endif /* yield_termstructure_h */
