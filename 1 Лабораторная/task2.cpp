#include <iostream>

int main(int argc, const char * argv[]){
    int a = 0, b = 0;

    std::cout << "Введите первое слагаемое: ";
    std::cin >> a;
    std::cout << "Введите второе слагаемое: ";
    std::cin >> b;
    std::cout << "Результат: " << a + b;

    return 0;
}