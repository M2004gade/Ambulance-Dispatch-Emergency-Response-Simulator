#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <vector>
#include <queue>

#include "Ambulance.h"
#include "Hospital.h"
#include "Emergency.h"

class Dispatcher {

private:

    std::vector<Ambulance> ambulances;

    std::vector<Hospital> hospitals;

    std::priority_queue<Emergency> emergencyQueue;

    std::vector<Emergency> emergencyHistory;

public:

    void addAmbulance(
        const Ambulance& ambulance
    );

    void addHospital(
        const Hospital& hospital
    );

    void reportEmergency(
        const Emergency& emergency
    );

    void viewAmbulances() const;

    void viewHospitals() const;

    void viewEmergencyQueue() const;

    Ambulance* findBestAmbulance(
        const Emergency& emergency
    );

    Hospital* findBestHospital(
        const Emergency& emergency
    );

    bool dispatchNextEmergency();

    void completeEmergency(int emergencyId);

    void viewHistory() const;

    int getTotalEmergencies() const;

    int getCriticalCount() const;

    int getHighCount() const;

    int getMediumCount() const;

    int getLowCount() const;
};

#endif