#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {

protected:
    int id;
    std::string name;
    int age;

public:

    Person(int id, const std::string& name, int age);

    virtual void display() const = 0;

    virtual ~Person() = default;
};

#endif