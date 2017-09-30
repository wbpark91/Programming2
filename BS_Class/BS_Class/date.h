#ifndef date_h
#define date_h

class Date {
public:
    Date(unsigned int year, unsigned int month, unsigned int day)
    : year_(year), month_(month), day_(day) {};
    unsigned int year() { return year_; }
    unsigned int month() { return month_; }
    unsigned int day() { return day_; }
private:
    unsigned int year_, month_, day_;
};

int daysBetween(Date d1, Date d2);

#endif /* date_h */