#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class BookFilter {
private:
    size_t minTitleLength;
    int minPages;

public:

    BookFilter(size_t n, int m) : minTitleLength(n), minPages(m) {}

    bool operator()(const std::pair<std::string, int>& book) const {
        return book.first.length() > minTitleLength && book.second > minPages;
    }
};

int main() {
    std::vector<std::pair<std::string, int>> books = {
        {"Война и мир", 1225},
        {"Преступление и наказание", 671},
        {"Мастер и Маргарита", 384},
        {"Идиот", 640},
        {"Анна Каренина", 864},
        {"Братья Карамазовы", 824},
        {"Евгений Онегин", 224},
        {"Герой нашего времени", 224}
    };

    std::cout << "Исходный список книг:" << std::endl;
    for (const auto& book : books) {
        std::cout << book.first << " (" << book.second << " стр.)" << std::endl;
    }

    BookFilter filter(10, 300);

    std::vector<std::pair<std::string, int>> filteredBooks;

    std::copy_if(books.begin(), books.end(), 
                std::back_inserter(filteredBooks), 
                filter);

    std::cout << "\nОтфильтрованный список книг (название > 10 символов и > 300 страниц):" << std::endl;
    for (const auto& book : filteredBooks) {
        std::cout << book.first << " (" << book.second << " стр.)" << std::endl;
    }

    return 0;
}
