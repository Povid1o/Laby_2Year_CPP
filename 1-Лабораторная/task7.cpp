#include <iostream>

int main(int argc, const char * argv[]){
    int a = 0, b = 0, c = 0;

    std::cout << "Введите первое число: ";
        std::cin >> a;
    std::cout << "Введите второе число: ";
        std::cin >> b;
    std::cout << "Введите третье число: ";
        std::cin >> c;

    std::cout << "ср.арифметическое трех чисел: " << (a + b + c) /3.;


    return 0;
}