#include "yield_termstructure.h"

std::vector<int> YieldTermStructure::findBetweenDates(Date d) {
    std::vector<int> result;
    for (int i = 0; i < dates_.size() - 1; ++i) {
        if (dates_[i] <= d && d <= dates_[i+1]) {
            result.push_back(i);
            result.push_back(i+1);
            break;
        }
    }
    return result;
}

double YieldTermStructure::rate(Date d) {
    std::vector<int> idx = findBetweenDates(d);
    int len = daysBetween(dates_[idx[0]], dates_[idx[1]]);
    int len1 = daysBetween(dates_[idx[0]], d);
    int len2 = daysBetween(d, dates_[idx[1]]);
    
    double rate = rates_[idx[0]] * len2 / len + rates_[idx[1]] * len1 / len;
    return rate;
}

double YieldTermStructure::discount(Date d) {
    double t = daysBetween(dates_[0], d) / 365.0;      // 평가일(첫번째 component)과 d일 사이의 기간(연 단위)
    return exp(-rate(d) * t);
}

double YieldTermStructure::forwardRate(Date d1, Date d2) {
    double df1 = discount(d1);
    double df2 = discount(d2);
    double tau = 365.0 / daysBetween(d1, d2);
    double forwardRate = (df1/df2 - 1) * tau;
    return forwardRate;
}
