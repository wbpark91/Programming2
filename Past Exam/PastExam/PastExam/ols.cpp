#include "header.h"

double* OLS::params() {
    double* result = new double[2];
    double sum_x = 0;
    double sum_y = 0;
    double sum_xy = 0;
    double sum_x_sq = 0;
    int n = x_.size();
    
    for (int i = 0; i < n; ++i) {
        sum_x += x_[i];
        sum_y += y_[i];
        sum_xy += x_[i] * y_[i];
        sum_x_sq += x_[i] * x_[i];
    }
    result[1] = (n*sum_xy - (sum_x*sum_y)) / (n*sum_x_sq - (sum_x*sum_x));
    result[0] = (sum_y / n) - result[1] * sum_x / n;
    
    return result;
}
