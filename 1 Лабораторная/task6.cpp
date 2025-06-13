#include <iostream>

int main(int argc, const char * argv[]){
    int a = 0, b = 0;
    char arOperator {};

    std::cout << "Введите первое число: ";
        std::cin >> a;
    std::cout << "Введите второе число: ";
        std::cin >> b;
    std::cout << "Введите арефметическую операцию ('+','-','*','/'): ";
        std::cin >> arOperator;

    switch(arOperator){
        case '+':
            std::cout << a + b <<std::endl;
            break;
        case '-':
            std::cout << a - b <<std::endl;
            break;
        case '*':
            std::cout << a * b <<std::endl;
            break;
        case '/':
            std::cout << a / b <<std::endl;
            break;
    }

    return 0;
}