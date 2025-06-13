#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

namespace Library {
    class Book {
    private:
        string title;
        
    public:
        Book(string bookTitle) : title(bookTitle) {
            cout << "Создана книга: " << title << endl;
        }
        
        ~Book() {
            cout << "Удалена книга: " << title << endl;
        }
        
        string getTitle() const {
            return title;
        }
    };
}

int main() {
    vector<shared_ptr<Library::Book>> books;

    books.push_back(make_shared<Library::Book>("ЗомбиПопакалипсис"));
    books.push_back(make_shared<Library::Book>("Преступление и преступление"));
    books.push_back(make_shared<Library::Book>("Мастер и Маргарин"));

    cout << "\nСписок книг:" << endl;
    for (const auto& book : books) {
        cout << "- " << book->getTitle() << endl;
    }

    return 0;
}
