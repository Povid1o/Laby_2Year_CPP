#include <iostream>

class Counter {
private:
    int value;
public:
    Counter(int v = 0) : value(v) {}

    Counter& operator++() {
        ++value;
        return *this;
    }

    Counter operator++(int) {
        Counter temp = *this;
        ++value;
        return temp;
    }

    int get() const { return value; }
};

int main() {
    Counter c(5);
    std::cout << "Исходное значение: " << c.get() << std::endl;
    ++c;
    std::cout << "После префиксного ++: " << c.get() << std::endl;
    c++;
    std::cout << "После постфиксного ++: " << c.get() << std::endl;
    return 0;
}
