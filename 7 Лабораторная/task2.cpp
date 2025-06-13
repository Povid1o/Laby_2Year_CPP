#include <iostream>

class Shape {
public:
    virtual void draw() const { std::cout << "Рисуем фигуру." << std::endl; }
};

class Circle : public Shape {
public:
    void draw() const override { std::cout << "Рисуем круг." << std::endl; }
};

class Square : public Shape {
public:
    void draw() const override { std::cout << "Рисуем квадрат." << std::endl; }
};

class Triangle : public Shape {
public:
    void draw() const override { std::cout << "Рисуем треугольник." << std::endl; }
};

int main() {
    Shape* shapes[] = { new Circle(), new Square(), new Triangle() };
    for (auto* s : shapes) {
        s->draw();
        delete s;
    }
    return 0;
}
