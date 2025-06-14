#include <iostream>

using namespace std;

int main() {
    int* numbers = new int[10];

    for (int i = 0; i < 10; i++) {
        numbers[i] = i + 1;
    }

    cout << "Массив: ";
    for (int i = 0; i < 10; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    delete[] numbers;
    
    return 0;
}