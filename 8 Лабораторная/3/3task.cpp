#include <iostream>
#include "collection.h"

struct Person { virtual ~Person()=default; virtual void say() const = 0; };

struct Preschool : Person { void say() const override { std::cout<<"I play!\n"; } };
struct Pupil     : Person { void say() const override { std::cout<<"I study at school.\n"; } };
struct Student   : Person { void say() const override { std::cout<<"Need coffee for exams...\n"; } };
struct Worker    : Person { void say() const override { std::cout<<"Back to the office.\n"; } };

int main(){
    PointerArray<Person> people;
    people.push_back(new Preschool);
    people.push_back(new Pupil);
    people.push_back(new Student);
    people.push_back(new Worker);

    for(auto p: people) p->say();
    return 0;
}
