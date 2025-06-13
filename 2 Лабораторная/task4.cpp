#include <iostream>
#include <cstring>
using namespace std;


int main(int argc, const char * argv[]){
    string userNum {};
    int result {};

    cout << "Введите число: ";
    cin >> userNum;

    for(char c : userNum){
        result += c - '0';
        
    }
    cout << "Сумма цифр числа: "<< result;
}