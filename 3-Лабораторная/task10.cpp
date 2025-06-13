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

    books.push_back(make_shared<Library::Book>("Ого, я сценарист"));
    books.push_back(make_shared<Library::Book>("Преступление и преступление и преступление и преступление и взятка и преступление и преступление"));
    books.push_back(make_shared<Library::Book>("Да как центрировать этот чёртов div"));

    cout << "\nСписок книг:" << endl;
    for (const auto& book : books) {
        cout << "- " << book->getTitle() << endl;
    }

    return 0;
}
