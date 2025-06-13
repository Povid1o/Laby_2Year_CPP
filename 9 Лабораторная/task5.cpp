#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    // Создаем первый вектор (0-9)
    std::vector<int> vec1(10);
    std::iota(vec1.begin(), vec1.end(), 0);

    // Создаем второй вектор (5-14)
    std::vector<int> vec2(10);
    std::iota(vec2.begin(), vec2.end(), 5);

    // Создаем вектор для результата пересечения
    std::vector<int> intersection;

    // Находим пересечение множеств
    std::set_intersection(vec1.begin(), vec1.end(),
                         vec2.begin(), vec2.end(),
                         std::back_inserter(intersection));

    // Выводим содержимое первого вектора
    std::cout << "Первый вектор (0-9):" << std::endl;
    for (int num : vec1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Выводим содержимое второго вектора
    std::cout << "\nВторой вектор (5-14):" << std::endl;
    for (int num : vec2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Выводим результат пересечения
    std::cout << "\nПересечение множеств:" << std::endl;
    for (int num : intersection) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
