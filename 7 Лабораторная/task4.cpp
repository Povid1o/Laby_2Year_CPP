#include <iostream>
#include <string>

class Person {
private:
    std::string name;
public:
    Person(const std::string& n) : name(n) {}
    std::string getName() const { return name; }
    void greet() const { std::cout << "Привет, я " << name << "." << std::endl; }
};

class Employee : public Person {
private:
    int id;
public:
    Employee(const std::string& n, int i) : Person(n), id(i) {}
    int getId() const { return id; }
    void work() const { std::cout << "Сотрудник " << getName() << " (ID: " << id << ") работает." << std::endl; }
};

class Manager : public Employee {
private:
    std::string department;
public:
    Manager(const std::string& n, int i, const std::string& dept) : Employee(n, i), department(dept) {}
    std::string getDepartment() const { return department; }
    void manage() const { std::cout << "Менеджер " << getName() << " (ID: " << getId() << ") управляет отделом " << department << "." << std::endl; }
};

int main() {
    Person p("Иван");
    Employee e("Андрей", 123);
    Manager m("Борис", 456, "IT");
    p.greet();
    e.greet();
    e.work();
    m.greet();
    m.work();
    m.manage();
    return 0;
}
