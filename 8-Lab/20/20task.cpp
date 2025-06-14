#include <iostream>
#include "collection.h"
#include "iterator.h"

struct Func { virtual double operator()(double x) const = 0; virtual ~Func(){} };

struct Const   : Func { double c; explicit Const(double C):c(C){} double operator()(double) const override{return c;} };
struct Linear  : Func { double k,b; Linear(double K,double B):k(K),b(B){} double operator()(double x) const override{return k*x+b;} };
struct Parabola: Func { double a,b,c; Parabola(double A,double B,double C):a(A),b(B),c(C){} double operator()(double x) const override{return a*x*x+b*x+c;} };

int main(){
    PointerArray<Func> fs;
    fs.push_back(new Const(3));
    fs.push_back(new Linear(2,1));
    fs.push_back(new Parabola(1,0,0));

    ArrIterator<PointerArray<Func>> it(fs,0), end(fs,3);
    for (double x : {0.0, 1.0, 2.0}) {
        std::cout << "x=" << x << " -> ";
        for (ArrIterator<PointerArray<Func>> it(fs, 0);  
             it != end; ++it)
        {
            std::cout << (**it)(x) << "  ";
        }
        std::cout << '\n';
    }
}
