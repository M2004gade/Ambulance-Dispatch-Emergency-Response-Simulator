#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdexcept>
#include <string>

inline void validateAge(int age) {

    if (age <= 0 || age > 120) {

        throw std::invalid_argument(
            "Invalid patient age."
        );
    }
}

inline void validateName(
    const std::string& name
) {

    if (name.empty()) {

        throw std::invalid_argument(
            "Patient name cannot be empty."
        );
    }
}

#endif