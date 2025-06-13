#include <iostream>

int main(int argc, const char * argv[]){
    int number = 0;

    std::cout << "Введите целое число: ";
    std::cin >> number;
    if (number % 2 == 0){
        std::cout << "Ваше число четное ";
    } else{
        std::cout << "Ваше число НЕ четное";
    } 
    return 0;
}