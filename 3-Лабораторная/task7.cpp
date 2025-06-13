#include <iostream>
#include <new>

using namespace std;

int main() {
    try {
        int* hugeArray = new int[10000000000000000];

        cout << "Память успешно выделена!" << endl;

        delete[] hugeArray;
    }
    catch (const bad_alloc& e) {
        cout << "Out of memory!" << endl;
    }
    
    return 0;
}