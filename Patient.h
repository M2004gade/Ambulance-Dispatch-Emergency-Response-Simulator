#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"

class Patient : public Person {

private:

    std::string medicalCondition;

public:

    Patient(
        int id,
        const std::string& name,
        int age,
        const std::string& condition
    );

    void display() const override;

    std::string getName() const;

    int getAge() const;
};

#endif