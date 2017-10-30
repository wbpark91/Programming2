#include "exam.h"
#include <iostream>
#include <random>
#include <cmath>

void howManyMultiples(unsigned int n) {
    int a, b;
    std::cout << "input 1 = ";
    std::cin >> a;
    std::cout << "input 2 = ";
    std::cin >> b;
    int result = 0;
    for (int i = a; i <= b; ++i) {
        if (i % n == 0)
            result += 1;
    }
    std::cout << "Number of multiples of " << n << " is " << result << std::endl;
}

double waitingTime(int n, int m) {
    int count = 0;
    std::mt19937_64 gen;
    std::normal_distribution<double> engine(0.0, 1.0);
    gen.seed(std::random_device{}());
    for (int i = 0; i < 10000; ++i) {
        double time = 0;
        for (int j = 0; j < n; ++j) {
            double e = engine(gen);
            time += exp(e);
        }
        if (time < m)
            count += 1;
    }
    return (double)count / 10000;
}

double Pension::calcAmount(double r) {
    double x = 1;
    for (int i = 1; i <= n_; ++i) {
        x *= (1/(1+r));
    }
    return a_ / ((1 - x) / r);
}
