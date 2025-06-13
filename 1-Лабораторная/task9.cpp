#include <iostream>
#include <cstring>


int main(int argc, const char * argv[]){

    std::string stringFromUser;
    std::string reverseString;

    std::cout << "Ваша строка, которая будет перевернута: " << std::endl;
        std::getline(std::cin, stringFromUser);

    for(int i = stringFromUser.length() - 1; i >= 0; i--){
        reverseString += stringFromUser[i];
    }

    std::cout << "Перевернутая строка: " << reverseString << std::endl;


    return 0;
}