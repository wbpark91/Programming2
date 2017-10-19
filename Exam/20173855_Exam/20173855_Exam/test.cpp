// 금융공학프로그래밍 II
// 학번: 20173855
// 이름: 박완배

#include "test.h"
#include <random>
#include <cmath>
#include <iostream>
#include <ctime>

double firstPassTime(double mu, double sigma, double b, unsigned int ns) {
    if (b <= 0 || b >= 1) {
        std::cout << "Value Error!" << std::endl;
        exit(1);
    }
    else {
        std::mt19937_64 gen;
        std::normal_distribution<double> engine(mu, sigma);
        gen.seed(std::random_device{}());
        int result = 0;
        for (unsigned int i = 0; i < ns; ++i) {
            double price = 1;
            int month = 1;
            while(true) {
                double r = engine(gen);
                price *= (1+r);
                if (price < b)
                    break;
                month += 1;
            }
            result += month;
        }
        return (double)result / ns;
    }
}

double bondprice(double couponRate, double yield, int T, int n) {
    double c = couponRate / n;
    double price = 0;
    for (int i = 1; i <= n*T; ++i) {
        double ti = i / n;
        price += c * exp(-yield * ti);
    }
    price += exp(-yield * T);
    return price;
}

double duration(double couponRate, double yield, int T, int n) {
    double p = bondprice(couponRate, yield, T, n);
    double c = couponRate / n;
    double duration = 0;
    for (int i = 1; i <= n*T; ++i) {
        double ti = i / n;
        duration += ti*c*exp(-yield*ti);
    }
    duration += T*exp(-yield*T);
    return duration / p;
}

double yield(double price, double couponRate, int T, int n) {
    double tol = 1e-8;
    double e = 1;
    double x = 0.05;
    while (e > tol) {
        double diff = bondprice(couponRate, x, T, n) - price;
        e = abs(diff);
        x = x - diff / (-duration(couponRate, x, T, n) * price);
    }
    return x;
}

double CompoundedRate::discount(double t) {
    return pow(1 + (rate_/n_), -n_*t);
}

double ContinuousRate::discount(double t) {
    return exp(-rate_*t);
}

Password::Password(const Password& p) {
    n_ = p.n_;
    password_ = new int[p.n_];
    for (int i = 0; i < n_; ++i) {
        password_[i] = p.password_[i];
    }
}

Password& Password::operator=(const Password& p) {
    delete[] password_;
    n_ = p.n_;
    password_ = new int[p.n_];
    for (int i = 0; i < n_; ++i) {
        password_[i] = p.password_[i];
    }
    return *this;
}

Password::Password(int n): n_(n) {
    password_ = new int[n_];
    srand((unsigned int)clock());       // Seed Allocation
    for (int i = 0; i < n_; ++i) {
        password_[i] = rand() % 10;
    }
}

void Password::printPassword() {
    std::cout << "Password = ";
    for (int i = 0; i < n_; ++i) {
        std::cout << password_[i];
    }
    std::cout << std::endl;
}
