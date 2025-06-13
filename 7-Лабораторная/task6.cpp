#include <iostream>

class Base {
public:
    Base() { std::cout << "Base constructor" << std::endl; }
    ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived constructor" << std::endl; }
    ~Derived() { std::cout << "Derived destructor" << std::endl; }
};

int main() {
    std::cout << "Создание объекта Derived через указатель на Base (невиртуальный деструктор):" << std::endl;
    Base* ptr = new Derived();
    delete ptr; // Утечка памяти, так как деструктор не виртуальный

    std::cout << "\nСоздание объекта Derived через указатель на Base (виртуальный деструктор):" << std::endl;
    Base* ptr2 = new Derived();
    delete ptr2; // Деструктор виртуальный, утечки нет
    return 0;
}
