#include <iostream>

int main(int argc, const char * argv[]){
    float c = {};

    std::cout << "Введите температуру в целсиях: ";
    std::cin >> c;
    std::cout << "Температура по фаренгейту: " << c * 9/5 + 32;

    return 0;
}