#include <iostream>
#include <stdexcept>

class NegativeNumberException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Ошибка: число отрицательное!";
    }
};

void processNumber(int x) {
    if (x < 0) {
        throw NegativeNumberException();
    }
    if (x > 100) {
        throw std::out_of_range("Ошибка: число больше 100!");
    }
    std::cout << "Число в допустимом диапазоне: " << x << std::endl;
}

int main() {
    try {
        processNumber(120);
    } catch (const NegativeNumberException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
