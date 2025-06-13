#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    int year;

    Book() : title(""), year(0) {}
    Book(const std::string& title, int year) : title(title), year(year) {}

    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "Название: " << book.title << ", Год: " << book.year;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Book& book) {
        std::cout << "Введите название книги: ";
        std::getline(is, book.title);
        std::cout << "Введите год издания: ";
        is >> book.year;
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера
        return is;
    }
};

int main() {
    Book b1;
    std::cin >> b1;
    std::cout << "Введённая книга: " << b1 << std::endl;
    return 0;
}
