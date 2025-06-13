#include <iostream>
#include <time.h>
using namespace std;


int main(int argc, const char * argv[]){
    srand(time(NULL));
    int randomNum = 1 + rand() % 100;
    int userNum {};

    cout << "Впишите предполагаемое число: ";
    cin >> userNum;

    while(randomNum != userNum){
        if (randomNum > userNum){
            cout << "Ваше число меньше, попробуйте еще раз!: ";
            cin >> userNum;
        } else{
            cout << "Ваше число больше, попробуйте еще раз!: ";
            cin >> userNum;
        }
    }

    cout << "Вы отгадали! Число: " << randomNum;

    return 0;
}