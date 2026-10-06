#include <iostream>
#include <limits>

#include "include/Patient.h"
#include "include/Ambulance.h"
#include "include/Hospital.h"
#include "include/Emergency.h"
#include "include/Dispatcher.h"
#include "include/Report.h"

using namespace std;

void loadDemoData(Dispatcher& dispatcher) {

    // =========================
    // AMBULANCE 1
    // =========================

    Ambulance a1(
        101,
        AmbulanceType::BASIC,
        Location(10, 10)
    );

    a1.addEquipment("Oxygen");
    a1.addEquipment("First Aid");

    dispatcher.addAmbulance(a1);

    // =========================
    // AMBULANCE 2
    // =========================

    Ambulance a2(
        102,
        AmbulanceType::ADVANCED,
        Location(20, 15)
    );

    a2.addEquipment("Oxygen");
    a2.addEquipment("ECG");
    a2.addEquipment("First Aid");

    dispatcher.addAmbulance(a2);

    // =========================
    // AMBULANCE 3
    // =========================

    Ambulance a3(
        103,
        AmbulanceType::ICU,
        Location(30, 25)
    );

    a3.addEquipment("Oxygen");
    a3.addEquipment("ECG");
    a3.addEquipment("Ventilator");
    a3.addEquipment("First Aid");

    dispatcher.addAmbulance(a3);

    // =========================
    // HOSPITAL 1
    // =========================

    Hospital h1(
        201,
        "City General Hospital",
        Location(40, 40),
        10,
        3
    );

    h1.addDepartment("Emergency");
    h1.addDepartment("Cardiology");
    h1.addDepartment("Trauma");

    dispatcher.addHospital(h1);

    // =========================
    // HOSPITAL 2
    // =========================

    Hospital h2(
        202,
        "Central Medical Center",
        Location(25, 35),
        8,
        5
    );

    h2.addDepartment("Emergency");
    h2.addDepartment("Neurology");
    h2.addDepartment("Cardiology");

    dispatcher.addHospital(h2);
}

void createEmergency(
    Dispatcher& dispatcher
) {

    int id;
    string name;
    int age;
    string condition;
    string type;
    string department;

    int severityChoice;

    double x;
    double y;

    cout << "\n========== REPORT EMERGENCY ==========\n";

    cout << "Patient ID: ";
    cin >> id;

    cin.ignore();

    cout << "Patient Name: ";
    getline(cin, name);

    cout << "Patient Age: ";
    cin >> age;

    cin.ignore();

    cout << "Medical Condition: ";
    getline(cin, condition);

    cout << "Emergency Type: ";
    getline(cin, type);

    cout << "\nSeverity:\n";

    cout << "1. Critical\n";
    cout << "2. High\n";
    cout << "3. Medium\n";
    cout << "4. Low\n";

    cout << "Enter choice: ";
    cin >> severityChoice;

    Severity severity;

    switch (severityChoice) {

        case 1:
            severity = Severity::CRITICAL;
            break;

        case 2:
            severity = Severity::HIGH;
            break;

        case 3:
            severity = Severity::MEDIUM;
            break;

        default:
            severity = Severity::LOW;
    }

    cout << "Emergency X coordinate: ";
    cin >> x;

    cout << "Emergency Y coordinate: ";
    cin >> y;

    cin.ignore();

    cout << "Required Hospital Department: ";
    getline(cin, department);

    Patient patient(
        id,
        name,
        age,
        condition
    );

    Emergency emergency(
        id,
        patient,
        type,
        severity,
        Location(x, y),
        department
    );

    int equipmentChoice;

    cout << "\nRequired Equipment:\n";

    cout << "1. Oxygen\n";
    cout << "2. ECG\n";
    cout << "3. Ventilator\n";
    cout << "4. None\n";

    cout << "Choose equipment: ";
    cin >> equipmentChoice;

    switch (equipmentChoice) {

        case 1:
            emergency.addRequiredEquipment("Oxygen");
            break;

        case 2:
            emergency.addRequiredEquipment("ECG");
            break;

        case 3:
            emergency.addRequiredEquipment("Ventilator");
            break;

        default:
            break;
    }

    dispatcher.reportEmergency(
        emergency
    );
}

int main() {

    Dispatcher dispatcher;

    loadDemoData(dispatcher);

    int choice;

    do {

        cout << "\n\n";
        cout << "==================================================\n";
        cout << "       🚑 AMBULANCE DISPATCH SYSTEM\n";
        cout << "==================================================\n";

        cout << "1. Report Emergency\n";
        cout << "2. View Emergency Queue\n";
        cout << "3. View Ambulances\n";
        cout << "4. View Hospitals\n";
        cout << "5. Dispatch Emergency\n";
        cout << "6. Complete Emergency\n";
        cout << "7. View Emergency History\n";
        cout << "8. Generate Report\n";
        cout << "0. Exit\n";

        cout << "\nEnter choice: ";

        cin >> choice;

        switch (choice) {

            case 1:

                createEmergency(
                    dispatcher
                );

                break;

            case 2:

                dispatcher.viewEmergencyQueue();

                break;

            case 3:

                dispatcher.viewAmbulances();

                break;

            case 4:

                dispatcher.viewHospitals();

                break;

            case 5:

                dispatcher.dispatchNextEmergency();

                break;

            case 6: {

                int id;

                cout
                    << "Enter Emergency ID: ";

                cin >> id;

                dispatcher.completeEmergency(id);

                break;
            }

            case 7:

                dispatcher.viewHistory();

                break;

            case 8:

                Report::generate(
                    dispatcher
                );

                break;

            case 0:

                cout
                    << "\nThank you for using the system.\n";

                break;

            default:

                cout
                    << "\nInvalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}