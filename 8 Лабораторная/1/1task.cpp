#include <iostream>
#include "collection.h"

struct Error { virtual ~Error() = default; virtual void info() const = 0; };

struct AccessViolation : Error {
    void* addr; explicit AccessViolation(void* a) : addr(a) {}
    void info() const override { std::cout << "Access violation at " << addr << '\n'; }
};
struct MathError : Error {};
struct ZeroDivide : MathError {
    double divident; explicit ZeroDivide(double d) : divident(d) {}
    void info() const override { std::cout << "Division by zero, value = " << divident << '\n'; }
};
struct Overflow : MathError {
    int a,b; Overflow(int x,int y):a(x),b(y){}
    void info() const override { std::cout << "Overflow: "<<a<<" * "<<b<<'\n'; }
};

int main(){
    PointerArray<Error> errs(3);
    errs[0] = new AccessViolation((void*)0xDEAD);
    errs[1] = new ZeroDivide(42.0);
    errs[2] = new Overflow(1<<30, 16);

    for(std::size_t i=0;i<3;++i) errs[i]->info();
    return 0;
}
