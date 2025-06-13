#include <iostream>
#include <cmath>
#include "collection.h"

struct Solid { virtual double volume() const = 0; virtual ~Solid(){} };

struct Cube : Solid {
    double a; explicit Cube(double A):a(A){}
    double volume() const override { return a*a*a; }
};
struct Cylinder : Solid {
    double r,h; Cylinder(double R,double H):r(R),h(H){}
    double volume() const override { return M_PI*r*r*h; }
};
struct Tetra : Solid {
    double a; explicit Tetra(double A):a(A){}
    double volume() const override { return a*a*a/std::sqrt(72.0); }
};

int main(){
    PointerArray<Solid> vec;
    vec.push_back(new Cube(2));
    vec.push_back(new Cylinder(1,5));
    vec.push_back(new Tetra(3));

    for(auto s:vec) std::cout<<s->volume()<<'\n';
}
