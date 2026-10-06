#include "../include/Hospital.h"

#include <iostream>
#include <algorithm>

Hospital::Hospital(
    int id,
    const std::string& name,
    Location location,
    int emergencyBeds,
    int icuBeds
)
    : id(id),
      name(name),
      location(location),
      emergencyBeds(emergencyBeds),
      icuBeds(icuBeds) {
}

void Hospital::addDepartment(
    const std::string& department
) {
    departments.push_back(department);
}

bool Hospital::hasDepartment(
    const std::string& department
) const {

    return std::find(
        departments.begin(),
        departments.end(),
        department
    ) != departments.end();
}

bool Hospital::hasEmergencyBed() const {
    return emergencyBeds > 0;
}

bool Hospital::hasICUBed() const {
    return icuBeds > 0;
}

void Hospital::useEmergencyBed() {

    if (emergencyBeds > 0)
        emergencyBeds--;
}

void Hospital::useICUBed() {

    if (icuBeds > 0)
        icuBeds--;
}

void Hospital::display() const {

    std::cout << "\n================================\n";

    std::cout << "Hospital ID       : " << id << '\n';

    std::cout << "Hospital Name     : "
              << name << '\n';

    std::cout << "Location          : ("
              << location.x << ", "
              << location.y << ")\n";

    std::cout << "Emergency Beds    : "
              << emergencyBeds << '\n';

    std::cout << "ICU Beds          : "
              << icuBeds << '\n';

    std::cout << "Departments       : ";

    if (departments.empty()) {

        std::cout << "None";

    } else {

        for (size_t i = 0; i < departments.size(); i++) {

            std::cout << departments[i];

            if (i < departments.size() - 1)
                std::cout << ", ";
        }
    }

    std::cout << '\n';

    std::cout << "================================\n";
}

int Hospital::getId() const {
    return id;
}

std::string Hospital::getName() const {
    return name;
}

Location Hospital::getLocation() const {
    return location;
}

int Hospital::getEmergencyBeds() const {
    return emergencyBeds;
}

int Hospital::getICUBeds() const {
    return icuBeds;
}

double Hospital::distanceTo(
    const Location& destination
) const {

    return location.distanceTo(destination);
}