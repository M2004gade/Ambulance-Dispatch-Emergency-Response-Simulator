#ifndef REPORT_H
#define REPORT_H

#include "Dispatcher.h"

class Report {

public:

    static void generate(
        const Dispatcher& dispatcher
    );
};

#endif