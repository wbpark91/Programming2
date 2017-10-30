#ifndef header_h
#define header_h
#include <valarray>
#include <vector>
#include <string>

int solveEquation(double* eq1, double* eq2, double* value);

class OLS {
public:
    OLS() {}
    OLS(std::valarray<double> x, std::valarray<double> y): x_(x), y_(y) {}
    double* params();
private:
    std::valarray<double> x_;
    std::valarray<double> y_;
};

class Formula {
public:
    Formula() {}
    Formula(std::string name): name_(name) {}
    virtual std::string getName() {
        return name_;
    }
    virtual double value(double t) = 0;
    virtual double firstDerivative(double t) = 0;
    virtual double secondDerivative(double t) = 0;
private:
    std::string name_;
};

class Polynomial: public Formula {
public:
    Polynomial() {}
    Polynomial(std::vector<double> coeff, std::string name = "Polynomial"): coeff_(coeff), Formula(name) {}
    virtual double value(double t);
    virtual double firstDerivative(double t);
    virtual double secondDerivative(double t);
private:
    std::vector<double> coeff_;
};

class Exp: public Formula {
public:
    Exp() {}
    Exp(double a, std::string name = "Exponential"): a_(a), Formula(name) {}
    virtual double value(double t);
    virtual double firstDerivative(double t);
    virtual double secondDerivative(double t);
private:
    double a_;
};

class Ln: public Formula {
public:
    Ln() {}
    Ln(double a, std::string name = "Logarithm"): a_(a), Formula(name) {}
    virtual double value(double t);
    virtual double firstDerivative(double t);
    virtual double secondDerivative(double t);
private:
    double a_;
};
#endif /* header_h */
