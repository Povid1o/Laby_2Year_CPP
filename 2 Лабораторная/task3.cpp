#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]){
    unsigned long userNum {};
    vector<unsigned long> divisors;

    cout << "Введите число что бы узнать простое ли оно: ";
    cin >> userNum;

    if (userNum < 2) {
        cout << userNum << " — ни простое, ни составное." << endl;
        return 0;
    }

    for (unsigned long i = 2; i * i <= userNum; i++) {
        if (userNum % i == 0) {
            divisors.push_back(i);
            if (i != userNum / i) {
                divisors.push_back(userNum / i);
            }
        }
    }


    if (divisors.empty()){
        cout << "Это простое число";
    }else{
        sort(divisors.begin(), divisors.end());

        cout << userNum <<" Является состовным числом так как делится на: " << "1, ";
        for (int num : divisors){
            cout << num <<", ";
        }
        cout << userNum <<".";
    }

    return 0;
}