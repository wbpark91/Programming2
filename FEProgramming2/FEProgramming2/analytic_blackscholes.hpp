#ifndef analytic_blackscholes_hpp
#define analytic_blackscholes_hpp

#define MAX(x, y)   (((x) > (y)) ? (x) : (y))

enum OptionType { Call = 1, Put = -1 };     // analytic price를 구하게 하는 곳에 이 변수가 들어가는 건 불편.

double bsprice(double s,
               double k,
               double r,
               double q,
               double t,
               double sigma,
               OptionType type);

double bsdelta(double s,
               double k,
               double r,
               double q,
               double t,
               double sigma,
               OptionType type);

double bsvega(double s,
              double k,
              double r,
              double q,
              double t,
              double sigma,
              OptionType type);

double bstheta(double s,
               double k,
               double r,
               double q,
               double t,
               double sigma,
               OptionType type);

double bsrho(double s,
             double k,
             double r,
             double q,
             double t,
             double sigma,
             OptionType type);

double bspsi(double s,
             double k,
             double r,
             double q,
             double t,
             double sigma,
             OptionType type);

double bsgamma(double s,
               double k,
               double r,
               double q,
               double t,
               double sigma,
               OptionType type);

double bsImpliedVol(double s,
                    double k,
                    double r,
                    double q,
                    double t,
                    double optionPrice,
                    OptionType type,
                    double init = 0.1,
                    double tol = 1e-6);

#endif /* analytic_blackscholes_hpp */
