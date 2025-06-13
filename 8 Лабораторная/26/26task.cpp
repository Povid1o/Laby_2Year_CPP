#include <iostream>
#include <cmath>
#include "collection.h"

struct F { virtual double v(double x) const = 0; virtual ~F(){} };

struct Exp  : F { double v(double x) const override { return std::exp(x);  } };
struct Sinh : F { double v(double x) const override { return std::sinh(x); } };
struct Cosh : F { double v(double x) const override { return std::cosh(x); } };

int main() {
    PointerArray<F> arr;
    arr.push_back(new Exp);
    arr.push_back(new Sinh);
    arr.push_back(new Cosh);

    for (double x : {0.0, 1.0, 2.0}) {
        std::cout << "x = " << x << " : ";
        for (auto f : arr) std::cout << f->v(x) << ' ';
        std::cout << '\n';
    }
    return 0;
}
