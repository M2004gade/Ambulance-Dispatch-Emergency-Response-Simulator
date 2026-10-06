#include "../include/Person.h"

Person::Person(
    int id,
    const std::string& name,
    int age
)
    : id(id), name(name), age(age) {
}