#ifndef exam_h
#define exam_h

void howManyMultiples(unsigned int n);

double waitingTime(int n, int m);

class Pension {
public:
    Pension() {}
    Pension(double a, double n): a_(a), n_(n) {}
    double calcAmount(double r);
private:
    double a_;
    unsigned int n_;
};

#endif /* exam_h */
