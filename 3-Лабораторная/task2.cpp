#include <iostream>

using namespace std;

namespace Game {

    namespace Physics {
        void applyGravity() {
            cout << "Gravity applied!" << endl;
        }
    }
}

int main() {

    Game::Physics::applyGravity();
    
    return 0;
}