#include <iostream>
using namespace std;


int main(int argc, const char * argv[]){
    int userNum {};
    double result {1};

    cout << "Таблица умножения для числа (1-10): ";
    cin >> userNum;

    if(userNum > 10 || userNum < 1){
        cout << "Вы ввели некоректное число, оно должно быть от 1 до 10 включительно!" << endl;
    } else{
        for (int i {1}; i < 10; i++){
        result = userNum * i;

        cout << endl << userNum << " * " << i << " = " << result;
        }
    }
    


    return 0;
}