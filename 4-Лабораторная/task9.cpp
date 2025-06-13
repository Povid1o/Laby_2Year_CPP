#include <iostream>
#include <new>

int main() {
    try {
        int* hugeArray = new int[100000000000000]; 

        std::cout << "Память успешно выделена!" << std::endl;

        delete[] hugeArray;
    } catch (const std::bad_alloc& e) {
        std::cerr << "Ошибка выделения памяти: " << e.what() << std::endl;
    }
    return 0;
}