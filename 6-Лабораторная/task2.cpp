#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int grade;

    Student(const std::string& name, int grade) : name(name), grade(grade) {}

    bool operator==(const Student& other) const {
        return this->grade == other.grade;
    }

    bool operator<(const Student& other) const {
        return this->name < other.name;
    }
};


int main() {
    Student s1("Иван", 5);
    Student s2("Андрей", 5);
    Student s3("Борис", 4);

    std::cout << "s1 == s2: " << (s1 == s2 ? "true" : "false") << std::endl;
    std::cout << "s1 == s3: " << (s1 == s3 ? "true" : "false") << std::endl;
    std::cout << "s2 < s3: " << (s2 < s3 ? "true" : "false") << std::endl;
    std::cout << "s3 < s1: " << (s3 < s1 ? "true" : "false") << std::endl;
    return 0;
}
