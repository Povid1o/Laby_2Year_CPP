#include <iostream>

class Engine {
public:
    void start() const { std::cout << "Двигатель запущен." << std::endl; }
    void stop() const { std::cout << "Двигатель остановлен." << std::endl; }
};


class CarInheritance : public Engine {
public:
    void drive() const { std::cout << "Машина едет." << std::endl; }
};


class CarComposition {
private:
    Engine engine;
public:
    void start() const { engine.start(); }
    void stop() const { engine.stop(); }
    void drive() const { std::cout << "Машина едет." << std::endl; }
};

int main() {
    CarInheritance car1;
    CarComposition car2;
    std::cout << "Машина через наследование:" << std::endl;
    car1.start();
    car1.drive();
    car1.stop();
    std::cout << "\nМашина через композицию:" << std::endl;
    car2.start();
    car2.drive();
    car2.stop();
    return 0;
}

/*Плюсы и минусы каждого подхода:
Наследование:
Плюсы: простота, прямое наследование всех методов базового класса.
Минусы: жёсткая связь, нарушение принципа "является" (машина не является двигателем).
Композиция:
Плюсы: гибкость, возможность замены двигателя, соблюдение принципа "имеет" (машина имеет двигатель).
Минусы: необходимость явного делегирования методов. */