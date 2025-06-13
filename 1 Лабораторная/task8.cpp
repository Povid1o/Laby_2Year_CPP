#include <iostream>

int main(int argc, const char * argv[]){
    int age = 0;

    std::cout << "Введите ваш возраст: ";
        std::cin >> age;

    age >= 18 ? std::cout << "Вы совершеннолетний" : std::cout << "Вы НЕсовершеннолетний";



    return 0;
}