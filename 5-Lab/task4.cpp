#include <iostream>
#include <string>
#include <stdexcept>

class BankAccount {
private:
    double balance;

public:
    std::string owner;

    BankAccount(const std::string& ownerName, double initialBalance = 0.0)
        : owner(ownerName), balance(initialBalance) {}

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

int main() {
    try {
        BankAccount account("Аноним Анонимычев", 1000.0);
        
        std::cout << "Владелец счета: " << account.owner << std::endl;
        std::cout << "Начальный баланс: " << account.getBalance() << " руб." << std::endl;

        account.deposit(500.0);
        std::cout << "После пополнения: " << account.getBalance() << " руб." << std::endl;

        account.withdraw(300.0);
        std::cout << "После снятия: " << account.getBalance() << " руб." << std::endl;

        account.withdraw(2000.0);
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    
    return 0;
}
