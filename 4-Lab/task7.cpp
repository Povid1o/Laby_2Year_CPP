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
        
