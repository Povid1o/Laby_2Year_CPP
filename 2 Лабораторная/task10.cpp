#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    double num1, num2;
    char operation;
    string command;
    
    while (true) {
        cout << "\nВведите первое число: ";
        cin >> num1;
        
        cout << "Введите операцию (+, -, *, /): ";
        cin >> operation;
        
        cout << "Введите второе число: ";
        cin >> num2;
        
        switch (operation) {
            case '+':
                cout << "Результат: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Результат: " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Результат: " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Результат: " << num1 / num2 << endl;
                } else {
                    cout << "Ошибка: деление на ноль!" << endl;
                }
                break;
            default:
                cout << "Ошибка: неверная операция!" << endl;
        }
        
        cout << "\nВведите 'выход' для завершения или любую другую строку для продолжения: ";
        cin >> command;
        
        if (command == "выход") {
            cout << "Программа завершена." << endl;
            break;
        }
    }
    
    return 0;
}