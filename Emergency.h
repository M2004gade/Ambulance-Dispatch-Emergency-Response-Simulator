#ifndef EMERGENCY_H
#define EMERGENCY_H

#include <string>
#include <vector>

#include "Patient.h"
#include "Location.h"

enum class Severity {
    CRITICAL = 1,
    HIGH = 2,
    MEDIUM = 3,
    LOW = 4
};

enum class EmergencyStatus {
    WAITING,
    DISPATCHED,
    TRANSPORTING,
    COMPLETED
};

class Emergency {

private:

    int id;

    Patient patient;

    std::string emergencyType;

    Severity severity;

    Location location;

    std::vector<std::string> requiredEquipment;

    std::string requiredDepartment;

    EmergencyStatus status;

    int assignedAmbulanceId;

    int assignedHospitalId;

public:

    Emergency(
        int id,
        Patient patient,
        const std::string& type,
        Severity severity,
        Location location,
        const std::string& department
    );

    void addRequiredEquipment(
        const std::string& equipment
    );

    void display() const;

    int getId() const;

    Patient getPatient() const;

    Severity getSeverity() const;

    Location getLocation() const;

    EmergencyStatus getStatus() const;

    std::vector<std::string>
    getRequiredEquipment() const;

    std::string getRequiredDepartment() const;

    void setStatus(EmergencyStatus status);

    void assignAmbulance(int id);

    void assignHospital(int id);

    int getAssignedAmbulance() const;

    int getAssignedHospital() const;

    bool operator<(const Emergency& other) const;

    std::string getSeverityString() const;

    std::string getStatusString() const;
};

#endif