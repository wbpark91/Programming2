#include "header.h"
#include <cmath>

int solveEquation(double* eq1, double* eq2, double* value) {
    double a1 = eq1[0];
    double b1 = eq1[1];
    double c1 = eq1[2];
    double a2 = eq2[0];
    double b2 = eq2[1];
    double c2 = eq2[2];
    
    double d = a1*b2 - a2*b1;
    
    if (d == 0) {
        if ((a1/a2) == (b1/b2) && (a1/a2) == (c1/c2) && (b1/b2) == (c1/c2))
            return 2;
        else
            return 1;
    }
    else {
        value[0] = (b2*c1 - b1*c2) / d;
        value[1] = (a1*c2 - a2*c1) / d;
        return 0;
    }
}

double Polynomial::value(double t) {
    double result = 0;
    for (int i = 0; i < coeff_.size(); ++i) {
        result += coeff_[i] * pow(t, i);
    }
    return result;
}

double Polynomial::firstDerivative(double t) {
    double result = 0;
    for (int i = 1; i < coeff_.size(); ++i) {
        result += coeff_[i] * pow(t, i-1) * i;
    }
    return result;
}

double Polynomial::secondDerivative(double t) {
    double result = 0;
    for (int i = 2; i < coeff_.size(); ++i) {
        result += coeff_[i] * pow(t, i-2) * i * (i-1);
    }
    return result;
}

double Exp::value(double t) {
    return exp(a_*t);
}

double Exp::firstDerivative(double t) {
    return a_*exp(a_*t);
}

double Exp::secondDerivative(double t) {
    return a_*a_*exp(a_*t);
}

double Ln::value(double t) {
    return a_*log(t);
}

double Ln::firstDerivative(double t) {
    return a_/t;
}

double Ln::secondDerivative(double t) {
    return -a_/(t*t);
}
