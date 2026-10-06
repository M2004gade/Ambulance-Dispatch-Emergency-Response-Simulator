#include "../include/Patient.h"
#include <iostream>

Patient::Patient(
    int id,
    const std::string& name,
    int age,
    const std::string& condition
)
    : Person(id, name, age),
      medicalCondition(condition) {
}

void Patient::display() const {

    std::cout << "\n========== PATIENT ==========\n";

    std::cout << "ID        : " << id << '\n';
    std::cout << "Name      : " << name << '\n';
    std::cout << "Age       : " << age << '\n';
    std::cout << "Condition : " << medicalCondition << '\n';
}

std::string Patient::getName() const {
    return name;
}

int Patient::getAge() const {
    return age;
}