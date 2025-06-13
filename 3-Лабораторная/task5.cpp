#include <iostream>
#include <string>

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
    Student* student = new Student("Andryha");

    cout << "Имя студента: " << student->getName() << endl;

    delete student;
    
    return 0;
}