#include "../include/Report.h"

#include <iostream>

void Report::generate(
    const Dispatcher& dispatcher
) {

    std::cout
        << "\n========================================\n";

    std::cout
        << "       EMERGENCY RESPONSE REPORT\n";

    std::cout
        << "========================================\n";

    std::cout
        << "Total Emergencies    : "
        << dispatcher.getTotalEmergencies()
        << '\n';

    std::cout
        << "Critical Emergencies : "
        << dispatcher.getCriticalCount()
        << '\n';

    std::cout
        << "High Emergencies     : "
        << dispatcher.getHighCount()
        << '\n';

    std::cout
        << "Medium Emergencies   : "
        << dispatcher.getMediumCount()
        << '\n';

    std::cout
        << "Low Emergencies      : "
        << dispatcher.getLowCount()
        << '\n';

    std::cout
        << "========================================\n";
}