#include <iostream>

class Base {
public:
    int pub;
    Base(int p, int pr, int pri) : pub(p), prot(pr), priv(pri) {}
    void print() const {
        std::cout << "Base: pub=" << pub << ", prot=" << prot << ", priv=" << priv << std::endl;
    }
protected:
    int prot;
private:
    int priv;
};

class DerivedPublic : public Base {
public:
    DerivedPublic(int p, int pr, int pri) : Base(p, pr, pri) {}
    void access() const {
        std::cout << "DerivedPublic: pub=" << pub << ", prot=" << prot << std::endl;
        // std::cout << "priv=" << priv << std::endl; // Ошибка: private недоступен
    }
};

class DerivedProtected : protected Base {
public:
    DerivedProtected(int p, int pr, int pri) : Base(p, pr, pri) {}
    void access() const {
        std::cout << "DerivedProtected: pub=" << pub << ", prot=" << prot << std::endl;
        // std::cout << "priv=" << priv << std::endl; // Ошибка: private недоступен
    }
};

class DerivedPrivate : private Base {
public:
    DerivedPrivate(int p, int pr, int pri) : Base(p, pr, pri) {}
    void access() const {
        std::cout << "DerivedPrivate: pub=" << pub << ", prot=" << prot << std::endl;
        // std::cout << "priv=" << priv << std::endl; // Ошибка: private недоступен
    }
};

int main() {
    DerivedPublic dp(1, 2, 3);
    DerivedProtected dprot(4, 5, 6);
    DerivedPrivate dpriv(7, 8, 9);
    dp.print(); // Доступно: public наследование
    dp.access();
    // dprot.print(); // Ошибка: protected наследование
    dprot.access();
    // dpriv.print(); // Ошибка: private наследование
    dpriv.access();
    return 0;
}
