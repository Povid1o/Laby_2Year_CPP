#include <iostream>

class Base {
public:
    virtual void foo() const { std::cout << "Base::foo()" << std::endl; }
    virtual void bar() const final { std::cout << "Base::bar()" << std::endl; }
};

class Derived : public Base {
public:
    void foo() const override { std::cout << "Derived::foo()" << std::endl; }
    // void bar() const override { std::cout << "Derived::bar()" << std::endl; } // Ошибка: bar() финальный
};

// class FurtherDerived : public Derived { // Ошибка: Derived финальный
// public:
//     void foo() const override { std::cout << "FurtherDerived::foo()" << std::endl; }
// };

int main() {
    Derived d;
    d.foo(); // Вызов переопределённого метода
    d.bar(); // Вызов финального метода из Base
    return 0;
}
