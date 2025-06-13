#include <iostream>

class Drawable {
public:
    virtual void draw() const = 0;
    virtual double getArea() const = 0;
};

class Rectangle : public Drawable {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    void draw() const override { std::cout << "Рисуем прямоугольник." << std::endl; }
    double getArea() const override { return width * height; }
};

class Circle : public Drawable {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    void draw() const override { std::cout << "Рисуем круг." << std::endl; }
    double getArea() const override { return 3.14159 * radius * radius; }
};

void printInfo(const Drawable& d) {
    d.draw();
    std::cout << "Площадь: " << d.getArea() << std::endl;
}

int main() {
    Rectangle r(3, 4);
    Circle c(5);
    printInfo(r);
    printInfo(c);
    return 0;
}
