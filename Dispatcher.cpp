#include "../include/Dispatcher.h"

#include <iostream>
#include <limits>

void Dispatcher::addAmbulance(
    const Ambulance& ambulance
) {
    ambulances.push_back(ambulance);
}

void Dispatcher::addHospital(
    const Hospital& hospital
) {
    hospitals.push_back(hospital);
}

void Dispatcher::reportEmergency(
    const Emergency& emergency
) {

    emergencyQueue.push(emergency);

    std::cout << "\nEmergency reported successfully.\n";
    std::cout << "Emergency ID: "
              << emergency.getId() << '\n';
}

void Dispatcher::viewAmbulances() const {

    std::cout << "\n========== AMBULANCES ==========\n";

    if (ambulances.empty()) {

        std::cout << "No ambulances available.\n";
        return;
    }

    for (const auto& ambulance : ambulances) {
        ambulance.display();
    }
}

void Dispatcher::viewHospitals() const {

    std::cout << "\n========== HOSPITALS ==========\n";

    if (hospitals.empty()) {

        std::cout << "No hospitals available.\n";
        return;
    }

    for (const auto& hospital : hospitals) {
        hospital.display();
    }
}

void Dispatcher::viewEmergencyQueue() const {

    std::cout << "\n========== EMERGENCY QUEUE ==========\n";

    if (emergencyQueue.empty()) {

        std::cout << "No waiting emergencies.\n";
        return;
    }

    auto temp = emergencyQueue;

    while (!temp.empty()) {

        temp.top().display();

        temp.pop();
    }
}

Ambulance* Dispatcher::findBestAmbulance(
    const Emergency& emergency
) {

    Ambulance* best = nullptr;

    double bestDistance =
        std::numeric_limits<double>::max();

    for (auto& ambulance : ambulances) {

        if (
            ambulance.getStatus()
            != AmbulanceStatus::AVAILABLE
        ) {
            continue;
        }

        if (
            !ambulance.hasEquipment(
                emergency.getRequiredEquipment()
            )
        ) {
            continue;
        }

        double distance =
            ambulance.distanceTo(
                emergency.getLocation()
            );

        if (distance < bestDistance) {

            bestDistance = distance;
            best = &ambulance;
        }
    }

    return best;
}

Hospital* Dispatcher::findBestHospital(
    const Emergency& emergency
) {

    Hospital* best = nullptr;

    double bestDistance =
        std::numeric_limits<double>::max();

    for (auto& hospital : hospitals) {

        if (!hospital.hasEmergencyBed()) {
            continue;
        }

        if (
            !hospital.hasDepartment(
                emergency.getRequiredDepartment()
            )
        ) {
            continue;
        }

        if (
            emergency.getSeverity()
            == Severity::CRITICAL
            && !hospital.hasICUBed()
        ) {
            continue;
        }

        double distance =
            hospital.distanceTo(
                emergency.getLocation()
            );

        if (distance < bestDistance) {

            bestDistance = distance;
            best = &hospital;
        }
    }

    return best;
}

bool Dispatcher::dispatchNextEmergency() {

    if (emergencyQueue.empty()) {

        std::cout
            << "\nNo emergencies waiting.\n";

        return false;
    }

    Emergency emergency =
        emergencyQueue.top();

    emergencyQueue.pop();

    Ambulance* ambulance =
        findBestAmbulance(emergency);

    if (ambulance == nullptr) {

        std::cout
            << "\nNo suitable ambulance available.\n";

        emergencyQueue.push(emergency);

        return false;
    }

    Hospital* hospital =
        findBestHospital(emergency);

    if (hospital == nullptr) {

        std::cout
            << "\nNo suitable hospital available.\n";

        emergencyQueue.push(emergency);

        return false;
    }

    ambulance->setStatus(
        AmbulanceStatus::DISPATCHED
    );

    emergency.assignAmbulance(
        ambulance->getId()
    );

    emergency.assignHospital(
        hospital->getId()
    );

    emergency.setStatus(
        EmergencyStatus::DISPATCHED
    );

    emergencyHistory.push_back(emergency);

    std::cout
        << "\n========================================\n";

    std::cout
        << "        EMERGENCY DISPATCHED\n";

    std::cout
        << "========================================\n";

    std::cout
        << "Emergency ID : "
        << emergency.getId() << '\n';

    std::cout
        << "Ambulance ID : "
        << ambulance->getId() << '\n';

    std::cout
        << "Ambulance    : "
        << ambulance->getTypeString() << '\n';

    std::cout
        << "Hospital     : "
        << hospital->getName() << '\n';

    std::cout
        << "Distance     : "
        << ambulance->distanceTo(
            emergency.getLocation()
        )
        << " units\n";

    std::cout
        << "========================================\n";

    return true;
}

void Dispatcher::completeEmergency(
    int emergencyId
) {

    for (auto& ambulance : ambulances) {

        if (
            ambulance.getStatus()
            == AmbulanceStatus::DISPATCHED
        ) {

            ambulance.setStatus(
                AmbulanceStatus::AVAILABLE
            );
        }
    }

    for (auto& emergency : emergencyHistory) {

        if (
            emergency.getId()
            == emergencyId
        ) {

            emergency.setStatus(
                EmergencyStatus::COMPLETED
            );

            std::cout
                << "\nEmergency "
                << emergencyId
                << " completed successfully.\n";

            return;
        }
    }

    std::cout
        << "\nEmergency not found.\n";
}

void Dispatcher::viewHistory() const {

    std::cout
        << "\n========== EMERGENCY HISTORY ==========\n";

    if (emergencyHistory.empty()) {

        std::cout
            << "No emergency history.\n";

        return;
    }

    for (const auto& emergency :
         emergencyHistory) {

        emergency.display();
    }
}

int Dispatcher::getTotalEmergencies() const {

    return static_cast<int>(
        emergencyHistory.size()
    );
}

int Dispatcher::getCriticalCount() const {

    int count = 0;

    for (const auto& emergency :
         emergencyHistory) {

        if (
            emergency.getSeverity()
            == Severity::CRITICAL
        ) {
            count++;
        }
    }

    return count;
}

int Dispatcher::getHighCount() const {

    int count = 0;

    for (const auto& emergency :
         emergencyHistory) {

        if (
            emergency.getSeverity()
            == Severity::HIGH
        ) {
            count++;
        }
    }

    return count;
}

int Dispatcher::getMediumCount() const {

    int count = 0;

    for (const auto& emergency :
         emergencyHistory) {

        if (
            emergency.getSeverity()
            == Severity::MEDIUM
        ) {
            count++;
        }
    }

    return count;
}

int Dispatcher::getLowCount() const {

    int count = 0;

    for (const auto& emergency :
         emergencyHistory) {

        if (
            emergency.getSeverity()
            == Severity::LOW
        ) {
            count++;
        }
    }

    return count;
}