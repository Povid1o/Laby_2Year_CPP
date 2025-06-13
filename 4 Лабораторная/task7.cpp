#include <iostream>
#include <stdexcept>

class Resource {
public:
    ~Resource() {

        throw std::runtime_error("Исключение в деструкторе!");
    }
};

int main() {
    try {
        Resource res;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
        // ПЛОХАЯ ПРАКТИКА: бросать исключения в деструкторе
        // Это может привести к:
        // 1. Неопределенному поведению при стековой раскрутке
        // 2. Утечкам ресурсов
        // 3. Двойному исключению