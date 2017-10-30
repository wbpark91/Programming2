#ifndef Date_hpp
#define Date_hpp
#include <iostream>

class Date {
public:
    Date() {}
    Date(unsigned int year, unsigned int month, unsigned int day)
    : year_(year), month_(month), day_(day) {}
    ~Date() {
        std:: cout << "소멸자 호출" << std::endl;
    }          // 소멸자
    unsigned int year()     { return year_; }           // 단순한 함수라 헤더에서 구현함
    unsigned int month()    { return month_; }
    unsigned int day()      { return day_; }
private:
    unsigned int year_, month_, day_;
};

int daysBetween(Date d1, Date d2);      // d1, d2는 "복사"가 되어서 넘어간다 (새롭게 생성)

#endif /* Date_hpp */
