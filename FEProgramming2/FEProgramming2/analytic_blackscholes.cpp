#include <cmath>
#include "analytic_blackscholes.hpp"
#include "normal.h"
#include <iostream>

double bsprice(double s,
               double k,
               double r,
               double q,
               double t,
               double sigma,
               OptionType type) {
    
    double d1 = (log(s / k) + (r - q + 0.5*sigma*sigma)*t) / (sigma*sqrt(t));
    double d2 = d1 - sigma*sqrt(t);
    double nd1 = normcdf(type*d1);
    double nd2 = normcdf(type*d2);
    double price = type*(s*exp(-q*t)*nd1 - k*exp(-r*t)*nd2);
    return price;
}

double bsdelta(double s,
               double k,
               double r,
               double q,
               double t,
               double sigma,
               OptionType type) {
    
    double d1 = (log(s / k) + (r - q + 0.5*sigma*sigma)*t) / (sigma*sqrt(t));
    double nd1 = normcdf(type*d1);
    double delta = type * exp(-q*t) * nd1;
    return delta;
}

double bsvega(double s,
              double k,
              double r,
              double q,
              double t,
              double sigma,
              OptionType type) {
    double d1 = (log(s / k) + (r - q + 0.5*sigma*sigma)*t) / (sigma*sqrt(t));
    double npd1 = normpdf(d1);
    double vega = s*exp(-q*t)*npd1*sqrt(t);
    return vega;
}

double bstheta(double s,
               double k,
               double r,
               double q,
               double t,
               double sigma,
               OptionType type) {
    double d1 = (log(s / k) + (r - q + 0.5*sigma*sigma)*t) / (sigma*sqrt(t));
    double d2 = d1 - sigma*sqrt(t);
    double pd1 = normpdf(d1);
    double nd1 = normcdf(type*d1);
    double nd2 = normcdf(type*d2);
    double theta = type*(exp(-q*t)*s*pd1*sigma*0.5/sqrt(t) - r*k*exp(-r*t)*nd2 + q*s*exp(-q*t)*nd1);
    return theta;
}

double bsrho(double s,
             double k,
             double r,
             double q,
             double t,
             double sigma,
             OptionType type) {
    double d1 = (log(s / k) + (r - q + 0.5*sigma*sigma)*t) / (sigma*sqrt(t));
    double d2 = d1 - sigma*sqrt(t);
    double nd2 = normcdf(type*d2);
    double rho = type*k*t*exp(-r*t)*nd2;
    return rho;
}

double bspsi(double s,
             double k,
             double r,
             double q,
             double t,
             double sigma,
             OptionType type) {
    double d1 = (log(s / k) + (r - q + 0.5*sigma*sigma)*t) / (sigma*sqrt(t));
    double nd1 = normcdf(type*d1);
    double psi = -type*s*t*exp(-q*t)*nd1;
    return psi;
}

double bsgamma(double s,
               double k,
               double r,
               double q,
               double t,
               double sigma,
               OptionType type) {
    double d1 = (log(s / k) + (r - q + 0.5*sigma*sigma)*t) / (sigma*sqrt(t));
    double pd1 = normpdf(d1);
    double gamma = exp(-q*t)*pd1/s/sigma/sqrt(t);
    return gamma;
}

double bsImpliedVol(double s,
                    double k,
                    double r,
                    double q,
                    double t,
                    double optionPrice,
                    OptionType type,
                    double init,
                    double tol) {
    
    double x = init;
    double e = 1;
    while (e > tol) {
        double diff = bsprice(s, k, r, q, t, x, type) - optionPrice;
        e = fabs(diff);
        x = x - diff / bsvega(s, k, r, q, t, x, type);
    }
    return x;
}
