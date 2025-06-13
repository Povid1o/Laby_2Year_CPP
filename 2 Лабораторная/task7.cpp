#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]){
  int n;
    cout << "Введите количество чисел ряда Фибоначчи : ";
    cin >> n;

    long long a = 0, b = 1;

    cout << "Первые " << n << " чисел ряда Фибоначчи:" << endl;

    for (int i = 0; i < n; ++i) {
        cout << a;
        if (i < n - 1) {
            cout << ", ";
        }

        long long next = a + b;
        a = b;
        b = next;
    }

    cout << endl;
    return 0;
}