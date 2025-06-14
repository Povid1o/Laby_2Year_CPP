#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int year;

public:

    Book(const std::string& t, const std::string& a, int y) 
        : title(t), author(a), year(y) {}

    void display() const {
        std::cout << "Название: " << title 
                  << ", Автор: " << author 
                  << ", Год: " << year << std::endl;
    }
};

int main() {
    Book book("Война и мир", "Лев Толстый", 1869);

    book.display();
    
    return 0;
}