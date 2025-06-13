#include <iostream>
#include <vector>

class Animal {
public:
    virtual void makeSound() const = 0; // Чистая виртуальная функция
};

class Dog : public Animal {
public:
    void makeSound() const override { std::cout << "Гав-гав!" << std::endl; }
};

class Cat : public Animal {
public:
    void makeSound() const override { std::cout << "Мяу-мяу!" << std::endl; }
};

class Cow : public Animal {
public:
    void makeSound() const override { std::cout << "Му-у-у!" << std::endl; }
};

void playSounds(const std::vector<Animal*>& animals) {
    for (const auto* a : animals) {
        a->makeSound();
    }
}

int main() {
    std::vector<Animal*> animals = { new Dog(), new Cat(), new Cow() };
    playSounds(animals);
    for (auto* a : animals) delete a;
    return 0;
}
