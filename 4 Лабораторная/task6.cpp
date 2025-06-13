#include <iostream>
#include <stdexcept>

class Rectangle {
private:
    int width;
    int height;
    
public:
    Rectangle(int width, int height) {
        if (width < 0) {
            throw std::invalid_argument("Ошибка: ширина не может быть отрицательной!");
        }
        if (height < 0) {
            throw std::invalid_argument("Ошибка: высота не может быть отрицательной!");
        }
        this->width = width;
        this->height = height;
    }
};

int main() {
    try {
        Rectangle rect(-10, 20);
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
