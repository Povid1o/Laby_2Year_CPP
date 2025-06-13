#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    static int nod(int a, int b) {
        return b == 0 ? a : nod(b, a % b);
    }

    static int nok(int a, int b) {
        return (a * b) / nod(a, b);
    }

    void reduce() {
        int divisor = nod(numerator, denominator);
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
        int newDenominator = nok(denominator, other.denominator);
        int newNumerator = numerator * (newDenominator / denominator) +
                          other.numerator * (newDenominator / other.denominator);
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator-(const Fraction& other) const {
        int newDenominator = nok(denominator, other.denominator);
        int newNumerator = numerator * (newDenominator / denominator) -
                          other.numerator * (newDenominator / other.denominator);
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, 
                       denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Деление на ноль невозможно");
        }
        return Fraction(numerator * other.denominator,
                       denominator * other.numerator);
    }

    void display() const {
        std::cout << numerator << "/" << denominator;
    }
};

int main() {
    try {
        Fraction f1(1, 2);
        Fraction f2(1, 3); 

        std::cout << "Первая дробь: ";
        f1.display();
        std::cout << std::endl;

        std::cout << "Вторая дробь: ";
        f2.display();
        std::cout << std::endl;

        Fraction sum = f1 + f2;
        std::cout << "Сложение: ";
        sum.display();
        std::cout << std::endl;

        Fraction diff = f1 - f2;
        std::cout << "Вычитание: ";
        diff.display();
        std::cout << std::endl;

        Fraction prod = f1 * f2;
        std::cout << "Умножение: ";
        prod.display();
        std::cout << std::endl;

        Fraction quot = f1 / f2;
        std::cout << "Деление: ";
        quot.display();
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
