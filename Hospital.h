#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include <vector>

#include "Location.h"

class Hospital {

private:

    int id;

    std::string name;

    Location location;

    int emergencyBeds;

    int icuBeds;

    std::vector<std::string> departments;

public:

    Hospital(
        int id,
        const std::string& name,
        Location location,
        int emergencyBeds,
        int icuBeds
    );

    void addDepartment(
        const std::string& department
    );

    bool hasDepartment(
        const std::string& department
    ) const;

    bool hasEmergencyBed() const;

    bool hasICUBed() const;

    void useEmergencyBed();

    void useICUBed();

    void display() const;

    int getId() const;

    std::string getName() const;

    Location getLocation() const;

    int getEmergencyBeds() const;

    int getICUBeds() const;

    double distanceTo(
        const Location& destination
    ) const;
};

#endif