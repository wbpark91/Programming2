#ifndef mc_blackscholes_hpp
#define mc_blackscholes_hpp

#include "analytic_blackscholes.hpp"

double mcprice(double s,
               double k,
               double r,
               double q,
               double t,
               double sigma,
               OptionType type,
               unsigned int numOfSimulation);

#endif /* mc_blackscholes_hpp */
