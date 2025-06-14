#include <iostream>
#include <stdexcept>

int main() {

    auto checkZero = [](int x) {
        if (x == 0) {
            throw std::invalid_argument("Ошибка: число равно нулю!");
        }
        return x;
    };

    try {

        checkZero(0);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}