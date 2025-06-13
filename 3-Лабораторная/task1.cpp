#include <iostream>

using namespace std;

namespace MathUtils {
    const double PI = 3.1415;
    
    double square(double x) {
        return x * x;
    }
}
int main() {

    cout << "\nКвадрат числа 5: " << MathUtils::square(5) << endl;
    cout << "Значение PI: " << MathUtils::PI << endl;
    
    return 0;
}