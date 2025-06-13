#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int year;

public:
    Book() : title(""), author(""), year(0) {}

    Book(const std::string& t, const std::string& a, int y) 
        : title(t), author(a), year(y) {}

    // Деструктор
    ~Book() {
        std::cout << "Книга '" << title << "' уничтожена." << std::endl;
    }

    void display() const {
        std::cout << "Название: " << title 
                  << ", Автор: " << author 
                  << ", Год: " << year << std::endl;
    }
};

int main() {
    {

        Book book("Война и мир", "Лев Толстой", 1869);
        std::cout << "Информация о книге:" << std::endl;
        book.display();
    }
    
    std::cout << "\nОбъект вышел из области видимости." << std::endl;
    
    return 0;
}