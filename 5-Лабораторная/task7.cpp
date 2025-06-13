#include <iostream>
#include <string>
#include <stdexcept>

class BankAccount {
private:
    double balance;
    static int totalAccounts;

public:
    std::string owner;

    BankAccount(const std::string& ownerName, double initialBalance = 0.0)
        : owner(ownerName), balance(initialBalance) {
        totalAccounts++;
    }

    ~BankAccount() {
        totalAccounts--;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Сумма пополнения должна быть положительной");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Сумма снятия должна быть положительной");
        }
        if (amount > balance) {
            throw std::runtime_error("Недостаточно средств на счете");
        }
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};

int BankAccount::totalAccounts = 0;

class Engine {
private:
    int power;

public:
    Engine(int enginePower) : power(enginePower) {}

    void start() const {
        std::cout << "Двигатель запущен с мощностью " << power << " л.с." << std::endl;
    }
};

class Car {
private:
    Engine engine;
    std::string model;

public:

    Car(const std::string& carModel, int enginePower) 
        : model(carModel), engine(enginePower) {}

    void startCar() const {
        std::cout << "Запуск автомобиля " << model << "..." << std::endl;
        engine.start();
        std::cout << "Автомобиль заведен." << std::endl;
    }
};

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    try {
        std::cout << "Начальное количество счетов: " << BankAccount::getTotalAccounts() << std::endl;

        BankAccount account1("Аноним Анонимычев", 1000.0);
        std::cout << "Количество счетов после создания первого: " << BankAccount::getTotalAccounts() << std::endl;

        BankAccount account2("Никита Башлыков", 2000.0);
        std::cout << "Количество счетов после создания второго: " << BankAccount::getTotalAccounts() << std::endl;
        account1.deposit(500.0);
        account2.withdraw(300.0);

        std::cout << "\nБаланс первого счета: " << account1.getBalance() << " руб." << std::endl;
        std::cout << "Баланс второго счета: " << account2.getBalance() << " руб." << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    std::cout << "\nКоличество счетов после уничтожения: " << BankAccount::getTotalAccounts() << std::endl;

    Car car("Toyota Camry", 150);

    car.startCar();
    
    Calculator calc;

    int result1 = calc.add(5, 3);
    std::cout << "5 + 3 = " << result1 << std::endl;

    double result2 = calc.add(3.14, 2.86);
    std::cout << "3.14 + 2.86 = " << result2 << std::endl;

    int result3 = calc.add(10, 20, 30);
    std::cout << "10 + 20 + 30 = " << result3 << std::endl;

    return 0;
}
