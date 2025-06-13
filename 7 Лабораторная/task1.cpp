#include <iostream>

class Vehicle {
public:
    void start() const { std::cout << "Транспорт запущен." << std::endl; }
    void stop() const { std::cout << "Транспорт остановлен." << std::endl; }
};

class Car : public Vehicle {
public:
    void honk() const { std::cout << "Бип-бип!" << std::endl; }
};

class Bicycle : public Vehicle {
public:
    void ringBell() const { std::cout << "Динь-динь!" << std::endl; }
};

int main() {
    Car car;
    Bicycle bicycle;
    car.start();
    car.honk();
    car.stop();
    bicycle.start();
    bicycle.ringBell();
    bicycle.stop();
    return 0;
}
