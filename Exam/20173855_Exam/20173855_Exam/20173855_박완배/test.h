// 금융공학프로그래밍 II
// 학번: 20173855
// 이름: 박완배

#ifndef test_h
#define test_h

enum Frequency { Annual = 1, Semiannual = 2, Quarterly = 4 };

double firstPassTime(double mu, double sigma, double b, unsigned int ns);

double bondprice(double couponRate, double yield, int T, int n);

double duration(double couponRate, double yield, int T, int n);

double yield(double price, double couponRate, int T, int n);

class InterestRate {
public:
    InterestRate() {}
    InterestRate(double rate): rate_(rate) {}
    virtual ~InterestRate() {}
    virtual double discount(double t) = 0;
protected:
    double rate_;
};

class CompoundedRate: public InterestRate {
public:
    CompoundedRate() {}
    CompoundedRate(double rate, Frequency n): InterestRate(rate), n_(n) {}
    virtual double discount(double t);
private:
    Frequency n_;
};

class ContinuousRate: public InterestRate {
public:
    ContinuousRate() {}
    ContinuousRate(double rate): InterestRate(rate) {}
    virtual double discount(double t);
};

class Password {
public:
    Password() {}
    Password(int n);
    Password(const Password& p);
    ~Password() {
        delete[] password_;
    }
    Password& operator=(const Password& p);
    void printPassword();
private:
    int n_;
    int* password_;
};
#endif /* test_h */
