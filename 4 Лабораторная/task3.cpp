#include <iostream>
#include <cmath>
#include <stdexcept>

class NegativeNumberException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Ошибка: нельзя вычислить квадратный корень из отрицательного числа!";
    }
};

double safeSqrt(double x) {
    if (x < 0) {
        throw NegativeNumberException();
    }
    return std::sqrt(x);
}

int main() {
    try {
        std::cout << safeSqrt(-1) << std::endl;
    } catch (const NegativeNumberException& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
