#include <iostream>
#include <cmath>
#include "collection.h"

struct Func { virtual double val(double x) const = 0; virtual ~Func(){} };

struct Log10 : Func { double val(double x) const override { return std::log10(x); } };
struct Ln    : Func { double val(double x) const override { return std::log(x);    } };

struct Derivative : Func {
    const Func& f;
    double h;
    Derivative(const Func& F, double H = 1e-5) : f(F), h(H) {}
    double val(double x) const override { return (f.val(x + h) - f.val(x - h)) / (2 * h); }
};

int main() {
    auto* lg   = new Log10;
    auto* ln   = new Ln;
    auto* d_lg = new Derivative(*lg);
    auto* d_ln = new Derivative(*ln);

    PointerArray<Func> funcs;
    funcs.push_back(lg);
    funcs.push_back(ln);
    funcs.push_back(d_lg);
    funcs.push_back(d_ln);

    for (double x : {1.0, 2.718281828, 10.0}) {
        std::cout << "x = " << x << " : ";
        for (auto f : funcs) std::cout << f->val(x) << ' ';
        std::cout << '\n';
    }
    return 0;
}
