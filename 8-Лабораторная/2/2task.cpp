#include <iostream>
#include "collection.h"

struct Vehicle { virtual ~Vehicle(){}; virtual void move() const = 0; };

struct Bicycle   : Vehicle { void move() const override { std::cout<<"Pedalling bicycle\n"; } };
struct Car       : Vehicle { void move() const override { std::cout<<"Driving car\n"; } };
struct Truck     : Vehicle { void move() const override { std::cout<<"Hauling with truck\n"; } };

int main(){
    PointerArray<Vehicle> park;
    park.push_back(new Bicycle);
    park.push_back(new Car);
    park.push_back(new Truck);

    for(auto v: park) v->move();
    return 0;
}
