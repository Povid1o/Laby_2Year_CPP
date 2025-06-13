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

class Student {
private:
    std::string name;
    int age;

public:

    Student(const std::string& studentName, int studentAge)
        : name(studentName), age(studentAge) {}


    Student(const Student& other)
        : name(other.name), age(other.age) {
        std::cout << "Вызван конструктор копирования" << std::endl;
    }

    void display() const {
        std::cout << "Имя: " << name << ", Возраст: " << age << std::endl;
    }
};

class Fraction {
private:
    int numerator;
    int denominator;

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }

    void reduce() {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

public:
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            throw std::invalid_argument("Знаменатель не может быть равен нулю");
        }
        reduce();
    }

    Fraction operator+(const Fraction& other) const {
        int newDenominator = lcm(denominator, other.denominator);
        int newNumerator = numerator * (newDenominator / denominator) +
                          other.numerator * (newDenominator / other.denominator);
        
        Fraction result(newNumerator, newDenominator);
        return result;
    }

    void display() const {
        std::cout << numerator << "/" << denominator;
    }
};

int main() {
    try {
        std::cout << "Начальное количество счетов: " << BankAccount::getTotalAccounts() << std::endl;

        BankAccount account1("Андрей Грабковский", 1000.0);
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

    Student student1("Иван Грабковский", 20);
    std::cout << "Первый студент:" << std::endl;
    student1.display();

    Student student2(student1);
    std::cout << "\nВторой студент (копия первого):" << std::endl;
    student2.display();

    Fraction f1(1, 2);
    Fraction f2(1, 3);

    std::cout << "Первая дробь: ";
    f1.display();
    std::cout << std::endl;

    std::cout << "Вторая дробь: ";
    f2.display();
    std::cout << std::endl;

    Fraction sum = f1 + f2;

    std::cout << "Сумма дробей: ";
    sum.display();
    std::cout << std::endl;

    return 0;
}