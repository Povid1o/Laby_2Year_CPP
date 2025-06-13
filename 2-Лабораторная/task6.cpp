#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]){
    int userNum1 {};
    int userNum2 {};
    int userNum3 {};
    int bufferResult{};
    

    cout << "Введите первое число: ";
    cin >> userNum1;
    cout << "Введите второе число: ";
    cin >> userNum2;
    cout << "Введите третье число: ";
    cin >> userNum3;

    int result[3] {userNum1, userNum2, userNum3};

    for(int i = 0; i < 2; i++){
        if(result[i] > result[i + 1]){
            bufferResult = result[i];
            result[i] = result[i + 1];
            result[i + 1] = bufferResult;
            i = -1;
        }else{}
    }
    cout << result[0] << ", " << result[2];
}