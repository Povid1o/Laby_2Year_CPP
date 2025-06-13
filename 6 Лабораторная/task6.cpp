#include <iostream>

class Rectangle {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    friend double calculateArea(const Rectangle& rect);
};

double calculateArea(const Rectangle& rect) {
    return rect.width * rect.height;
}

int main() {
    Rectangle r(3.5, 2.0);
    std::cout << "Площадь прямоугольника: " << calculateArea(r) << std::endl;
    return 0;
}
