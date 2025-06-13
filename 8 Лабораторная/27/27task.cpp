#include <iostream>
#include <cmath>
#include "collection.h"

struct Func { virtual double operator()(double x) const = 0; virtual ~Func(){} };

struct Pow : Func {
    double n;
    explicit Pow(double N) : n(N) {}
    double operator()(double x) const override { return std::pow(x, n); }
};

struct ExpA : Func {
    double A, B;
    ExpA(double a, double b) : A(a), B(b) {}
    double operator()(double x) const override { return A * std::pow(B, x); }
};

int main() {
    PointerArray<Func> fs;
    fs.push_back(new Pow(2.0));       // x²
    fs.push_back(new Pow(0.5));       // √x
    fs.push_back(new ExpA(1.0, 2.0)); // 2ˣ

    for (double x : {1.0, 2.0, 4.0}) {
        std::cout << "x = " << x << " : ";
        for (auto f : fs) std::cout << (*f)(x) << ' ';
        std::cout << '\n';
    }
    return 0;
}
