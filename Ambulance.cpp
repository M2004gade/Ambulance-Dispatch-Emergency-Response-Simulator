#include "../include/Ambulance.h"

#include <iostream>
#include <algorithm>

Ambulance::Ambulance(
    int id,
    AmbulanceType type,
    Location location
)
    : id(id),
      type(type),
      status(AmbulanceStatus::AVAILABLE),
      location(location) {
}

void Ambulance::addEquipment(
    const std::string& item
) {
    equipment.push_back(item);
}

bool Ambulance::hasEquipment(
    const std::vector<std::string>& required
) const {

    for (const auto& item : required) {

        bool found = false;

        for (const auto& available : equipment) {

            if (available == item) {
                found = true;
                break;
            }
        }

        if (!found)
            return false;
    }

    return true;
}

void Ambulance::display() const {

    std::cout << "\n--------------------------------\n";

    std::cout << "Ambulance ID : " << id << '\n';

    std::cout << "Type         : "
              << getTypeString() << '\n';

    std::cout << "Status       : "
              << getStatusString() << '\n';

    std::cout << "Location     : ("
              << location.x << ", "
              << location.y << ")\n";

    std::cout << "Equipment    : ";

    if (equipment.empty()) {
        std::cout << "None";
    }
    else {

        for (size_t i = 0; i < equipment.size(); i++) {

            std::cout << equipment[i];

            if (i < equipment.size() - 1)
                std::cout << ", ";
        }
    }

    std::cout << '\n';

    std::cout << "--------------------------------\n";
}

int Ambulance::getId() const {
    return id;
}

AmbulanceType Ambulance::getType() const {
    return type;
}

AmbulanceStatus Ambulance::getStatus() const {
    return status;
}

Location Ambulance::getLocation() const {
    return location;
}

void Ambulance::setStatus(
    AmbulanceStatus newStatus
) {
    status = newStatus;
}

void Ambulance::setLocation(
    Location newLocation
) {
    location = newLocation;
}

double Ambulance::distanceTo(
    const Location& destination
) const {

    return location.distanceTo(destination);
}

std::string Ambulance::getTypeString() const {

    switch (type) {

        case AmbulanceType::BASIC:
            return "Basic";

        case AmbulanceType::ADVANCED:
            return "Advanced";

        case AmbulanceType::ICU:
            return "ICU";
    }

    return "Unknown";
}

std::string Ambulance::getStatusString() const {

    switch (status) {

        case AmbulanceStatus::AVAILABLE:
            return "Available";

        case AmbulanceStatus::DISPATCHED:
            return "Dispatched";

        case AmbulanceStatus::BUSY:
            return "Busy";

        case AmbulanceStatus::MAINTENANCE:
            return "Maintenance";
    }

    return "Unknown";
}