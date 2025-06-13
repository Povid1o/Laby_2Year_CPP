#include <iostream>

class Distance {
private:
    double meters;
public:
    Distance(double m = 0) : meters(m) {}

    operator double() const {
        return meters / 1000.0;
    }

    double getMeters() const { return meters; }
};

int main() {
    Distance d(1234);
    std::cout << "В метрах: " << d.getMeters() << std::endl;
    double km = d; 
    std::cout << "В километрах: " << km << std::endl;
    return 0;
}
