#include <iostream>
#include <cmath>
#include "collection.h"

struct Shape { virtual double area() const = 0; virtual ~Shape(){}; };

struct Ellipse : Shape {
    double a,b; Ellipse(double A,double B):a(A),b(B){}
    double area() const override { return M_PI*a*b; }
};
struct Square : Shape {
    double a; explicit Square(double A):a(A){}
    double area() const override { return a*a; }
};
struct Trapezoid : Shape {
    double a,b,h; Trapezoid(double A,double B,double H):a(A),b(B),h(H){}
    double area() const override { return (a+b)*h/2; }
};

int main(){
    PointerArray<Shape> set;
    set.push_back(new Ellipse(3,2));
    set.push_back(new Square(4));
    set.push_back(new Trapezoid(3,5,2));

    for(auto s:set) std::cout<<s->area()<<'\n';
}
