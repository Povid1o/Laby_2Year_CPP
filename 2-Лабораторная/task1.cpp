#include <iostream>
using namespace std;


int main(int argc, const char * argv[]){
    int userNum {};
    double result {1};

    cout << "Впишите число, что бы узнать его факториал: ";
    cin >> userNum;

    for (int i {0}; i < userNum; i++){
        result = result * (i + 1);
    }

    cout << "Факториал " << userNum << " равен: "<< result << endl;


    return 0;
}