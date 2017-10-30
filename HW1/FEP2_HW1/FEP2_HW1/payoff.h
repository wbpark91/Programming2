#ifndef payoff_h
#define payoff_h
class Payoff {
public:
    virtual ~Payoff() {}
    virtual double operator()(double s) = 0;        // Operator overloading
};

#endif /* payoff_h */

