#include <iostream>

using namespace std;

int main() {
    // Создание одиночного числа
    int* a = new int(5);
    
    // Создание массива
    int* arr = new int[3]{1, 2, 3};
    
    // Вывод значений
    cout << "Одиночное число: " << *a << endl;
    cout << "Массив: ";
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Освобождение памяти
    delete a;    
    delete[] arr;
    
    return 0;
}
