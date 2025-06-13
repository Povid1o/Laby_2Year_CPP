#include <iostream>
#include <cmath>
#include "collection.h"

struct Figure { virtual double area() const = 0; virtual void  show() const = 0; virtual ~Figure(){} };

struct Circle : Figure {
    double r; explicit Circle(double R):r(R){}
    double area() const override { return M_PI*r*r;}
    void   show() const override { std::cout<<"Circle r="<<r<<" S="<<area()<<'\n';}
};
struct Rect : Figure {
    double a,b; Rect(double A,double B):a(A),b(B){}
    double area() const override { return a*b;}
    void   show() const override { std::cout<<"Rectangle "<<a<<"x"<<b<<" S="<<area()<<'\n';}
};
struct Triangle : Figure {
    double a,b,c; Triangle(double A,double B,double C):a(A),b(B),c(C){}
    double area() const override {
        double p=(a+b+c)/2; return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    void   show() const override { std::cout<<"Triangle S="<<area()<<'\n';}
};

int main(){
    PointerArray<Figure> figs;
    figs.push_back(new Circle(5));
    figs.push_back(new Rect(3,4));
    figs.push_back(new Triangle(3,4,5));

    for(auto f: figs) f->show();
}
