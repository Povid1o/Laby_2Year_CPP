#include <iostream>

class Printer {
public:
    void print() const { std::cout << "Печать документа..." << std::endl; }
};

class Scanner {
public:
    void scan() const { std::cout << "Сканирование документа..." << std::endl; }
};

class Copier : public Printer, public Scanner {
public:
    void copy() const {
        scan();
        print();
    }
};

int main() {
    Copier copier;
    copier.print();
    copier.scan();
    copier.copy();
    return 0;
}
