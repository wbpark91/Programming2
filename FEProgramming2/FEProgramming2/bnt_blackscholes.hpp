#ifndef bnt_blackscholes_hpp
#define bnt_blackscholes_hpp

#include "analytic_blackscholes.hpp"

double bntprice(double s,
                double k,
                double r,
                double q,
                double t,
                double sigma,
                OptionType type,
                unsigned int nsteps);

#endif /* bnt_blackscholes_hpp */
