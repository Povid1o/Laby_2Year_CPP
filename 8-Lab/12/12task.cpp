#include <iostream>
#include <complex>
#include "collection.h"

struct Number { virtual void print() const = 0; virtual ~Number(){} };

struct IntNum   : Number { int v; explicit IntNum(int x):v(x){} void print() const override{ std::cout<<"int "<<v<<'\n'; } };
struct RealNum  : Number { double v; explicit RealNum(double x):v(x){} void print() const override{ std::cout<<"double "<<v<<'\n'; } };
struct ComplexNum: Number { std::complex<double> v; ComplexNum(double r,double i):v(r,i){} void print() const override{ std::cout<<"complex "<<v<<'\n'; } };

int main(){
    PointerArray<Number> nums;
    nums.push_back(new IntNum(7));
    nums.push_back(new RealNum(3.14));
    nums.push_back(new ComplexNum(1,2));

    for(auto n:nums) n->print();
}
