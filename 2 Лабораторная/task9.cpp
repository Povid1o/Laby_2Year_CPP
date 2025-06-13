#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int number;
    int reversed = 0;
    
    cout << "Введите целое число: ";
    cin >> number;
    
    bool isNegative = number < 0;
    if (isNegative) {
        number = -number;
    }

    while (number > 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    
    if (isNegative) {
        reversed = -reversed;
    }
    
    cout << "Число в обратном порядке: " << reversed << endl;
    
    return 0;
}