#include <iostream>
#include <cmath>
#include "collection.h"

struct F { virtual double f(double x) const = 0; virtual ~F(){} };

struct Sin : F { double f(double x) const override { return std::sin(x); } };
struct Cos : F { double f(double x) const override { return std::cos(x); } };
struct Tan : F { double f(double x) const override { return std::tan(x); } };

int main() {
    PointerArray<F> arr;
    arr.push_back(new Sin);
    arr.push_back(new Cos);
    arr.push_back(new Tan);

    for (double x : {0.0, M_PI / 6.0, M_PI / 4.0}) {
        std::cout << "x = " << x << " : ";
        for (auto f : arr) std::cout << f->f(x) << ' ';
        std::cout << '\n';
    }
    return 0;
}
