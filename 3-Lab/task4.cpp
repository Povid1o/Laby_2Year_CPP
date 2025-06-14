#include <iostream>

using namespace std;


namespace A { 
    int x = 10; 
}

namespace B { 
    int x = 20; 
}

int main() {
    cout << "A::x = " << A::x << endl;
    cout << "B::x = " << B::x << endl;
    
    //V 2
    using A::x; 
    cout << "x = " << x << endl;
    
    return 0;
}