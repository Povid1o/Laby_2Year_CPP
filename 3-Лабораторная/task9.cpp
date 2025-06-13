#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Student {
private:
    string name;
    
public:
    Student(string studentName) : name(studentName) {
        cout << "Создан студент: " << name << endl;
    }

    ~Student() {
        cout << "Удален студент: " << name << endl;
    }

    string getName() const {
        return name;
    }
};

int main() {
    unique_ptr<Student> student = make_unique<Student>("Nikitka");

    cout << "Имя студента: " << student->getName() << endl;

    return 0;
}
