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

    void display() const {
        std::cout << "Название: " << title 
                  << ", Автор: " << author 
                  << ", Год: " << year << std::endl;
    }
};

int main() {
    Book emptyBook;
    std::cout << "Книга, созданная конструктором по умолчанию:" << std::endl;
    emptyBook.display();

    Book warAndPeace("Война и мир", "Лев Толстой", 1869);
    std::cout << "\nКнига, созданная конструктором с параметрами:" << std::endl;
    warAndPeace.display();
    
    return 0;
}