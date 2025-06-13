#include <iostream>
#include <stdexcept>

class Calculator {
public:
    int add(int a, int b) {
        int result = a + b;
        if (result > 1000) {
            throw std::overflow_error("Ошибка: результат сложения превышает 1000!");
        }
        return result;
    }
};

int main() {
    Calculator calc;
    try {
        std::cout << calc.add(500, 600) << std::endl;
    } catch (const std::overflow_error& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}