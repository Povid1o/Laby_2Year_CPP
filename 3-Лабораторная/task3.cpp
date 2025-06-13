#include <iostream>

using namespace std;

namespace VeryLongNamespaceName {
    void test() {
        cout << "Функция test() вызвана!" << endl;
    }
}

namespace Short = VeryLongNamespaceName;

int main() {

    Short::test();
    
    return 0;
}