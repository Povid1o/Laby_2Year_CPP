#include <iostream>

int main(int argc, const char * argv[]){
    int a = 0, b = 0;

    std::cout << "Введите длину прямоугольника: ";
    std::cin >> a;
    std::cout << "Введите ширину прямоугольника: ";
    std::cin >> b;
    std::cout << "площадь прямоугольника: " << a * b;

    return 0;
}