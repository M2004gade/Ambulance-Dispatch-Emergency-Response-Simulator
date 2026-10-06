#ifndef AMBULANCE_H
#define AMBULANCE_H

#include <string>
#include <vector>
#include "Location.h"

enum class AmbulanceType {
    BASIC,
    ADVANCED,
    ICU
};

enum class AmbulanceStatus {
    AVAILABLE,
    DISPATCHED,
    BUSY,
    MAINTENANCE
};

class Ambulance {

private:

    int id;

    AmbulanceType type;

    AmbulanceStatus status;

    Location location;

    std::vector<std::string> equipment;

public:

    Ambulance(
        int id,
        AmbulanceType type,
        Location location
    );

    void addEquipment(const std::string& item);

    bool hasEquipment(
        const std::vector<std::string>& required
    ) const;

    void display() const;

    int getId() const;

    AmbulanceType getType() const;

    AmbulanceStatus getStatus() const;

    Location getLocation() const;

    void setStatus(AmbulanceStatus newStatus);

    void setLocation(Location newLocation);

    double distanceTo(const Location& destination) const;

    std::string getTypeString() const;

    std::string getStatusString() const;
};

#endif