#include <iostream>
#include <vector>
#include "collection.h"

struct Progression { virtual double nth(int n) const = 0; virtual ~Progression(){} };

struct Arith : Progression {
    double a0,d; Arith(double A0,double D):a0(A0),d(D){}
    double nth(int n) const override { return a0 + d*(n-1); }
};
struct Geom : Progression {
    double a0,q; Geom(double A0,double Q):a0(A0),q(Q){}
    double nth(int n) const override { return a0*std::pow(q,n-1); }
};

int main(){
    PointerArray<Progression> p;
    p.push_back(new Arith(1,2));
    p.push_back(new Geom(1,2));

    for(int i=1;i<=5;++i){
        std::cout<<i<<": "<<p[0]->nth(i)<<", "<<p[1]->nth(i)<<"\n";
    }
}
