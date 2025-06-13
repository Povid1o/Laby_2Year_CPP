#include <iostream>

void riskyFunction() {
    throw "Неожиданная ошибка!";
}

int main() {
    try {
        riskyFunction();
    } catch (...) {
        std::cerr << "Поймано неизвестное исключение!" << std::endl;
    }
    return 0;
}
