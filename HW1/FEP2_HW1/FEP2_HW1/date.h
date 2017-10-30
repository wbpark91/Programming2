#ifndef date_h
#define date_h

class Date {
public:
    Date() { };
    Date(int year, int month, int day): year_(year), month_(month), day_(day) { };
    int year() { return year_; }
    int month() { return month_; }
    int day() { return day_; }
    bool operator > (Date& d);
    bool operator < (Date& d);
    bool operator == (Date& d);
    bool operator <= (Date& d);
    bool operator >= (Date& d);
    
private:
    int year_, month_, day_;
};

int daysBetween(Date d1, Date d2);
#endif /* date_h */
