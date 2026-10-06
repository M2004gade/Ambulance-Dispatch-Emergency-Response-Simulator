#include "../include/Emergency.h"

#include <iostream>

Emergency::Emergency(
    int id,
    Patient patient,
    const std::string& type,
    Severity severity,
    Location location,
    const std::string& department
)
    : id(id),
      patient(patient),
      emergencyType(type),
      severity(severity),
      location(location),
      requiredDepartment(department),
      status(EmergencyStatus::WAITING),
      assignedAmbulanceId(-1),
      assignedHospitalId(-1) {
}

void Emergency::addRequiredEquipment(
    const std::string& equipment
) {
    requiredEquipment.push_back(equipment);
}

void Emergency::display() const {

    std::cout << "\n====================================\n";

    std::cout << "Emergency ID       : "
              << id << '\n';

    std::cout << "Patient            : "
              << patient.getName() << '\n';

    std::cout << "Age                : "
              << patient.getAge() << '\n';

    std::cout << "Emergency Type     : "
              << emergencyType << '\n';

    std::cout << "Severity           : "
              << getSeverityString() << '\n';

    std::cout << "Location           : ("
              << location.x << ", "
              << location.y << ")\n";

    std::cout << "Department         : "
              << requiredDepartment << '\n';

    std::cout << "Required Equipment : ";

    if (requiredEquipment.empty()) {

        std::cout << "None";

    } else {

        for (size_t i = 0;
             i < requiredEquipment.size();
             i++) {

            std::cout << requiredEquipment[i];

            if (i < requiredEquipment.size() - 1)
                std::cout << ", ";
        }
    }

    std::cout << '\n';

    std::cout << "Status             : "
              << getStatusString() << '\n';

    std::cout << "Ambulance ID       : "
              << assignedAmbulanceId << '\n';

    std::cout << "Hospital ID        : "
              << assignedHospitalId << '\n';

    std::cout << "====================================\n";
}

int Emergency::getId() const {
    return id;
}

Patient Emergency::getPatient() const {
    return patient;
}

Severity Emergency::getSeverity() const {
    return severity;
}

Location Emergency::getLocation() const {
    return location;
}

EmergencyStatus Emergency::getStatus() const {
    return status;
}

std::vector<std::string>
Emergency::getRequiredEquipment() const {

    return requiredEquipment;
}

std::string Emergency::getRequiredDepartment() const {
    return requiredDepartment;
}

void Emergency::setStatus(
    EmergencyStatus newStatus
) {
    status = newStatus;
}

void Emergency::assignAmbulance(int id) {
    assignedAmbulanceId = id;
}

void Emergency::assignHospital(int id) {
    assignedHospitalId = id;
}

int Emergency::getAssignedAmbulance() const {
    return assignedAmbulanceId;
}

int Emergency::getAssignedHospital() const {
    return assignedHospitalId;
}

bool Emergency::operator<(
    const Emergency& other
) const {

    return static_cast<int>(severity)
         > static_cast<int>(other.severity);
}

std::string Emergency::getSeverityString() const {

    switch (severity) {

        case Severity::CRITICAL:
            return "CRITICAL";

        case Severity::HIGH:
            return "HIGH";

        case Severity::MEDIUM:
            return "MEDIUM";

        case Severity::LOW:
            return "LOW";
    }

    return "UNKNOWN";
}

std::string Emergency::getStatusString() const {

    switch (status) {

        case EmergencyStatus::WAITING:
            return "Waiting";

        case EmergencyStatus::DISPATCHED:
            return "Dispatched";

        case EmergencyStatus::TRANSPORTING:
            return "Transporting";

        case EmergencyStatus::COMPLETED:
            return "Completed";
    }

    return "Unknown";
}