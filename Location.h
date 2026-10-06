#ifndef LOCATION_H
#define LOCATION_H

#include <cmath>

struct Location {
    double x;
    double y;

    Location(double x = 0, double y = 0)
        : x(x), y(y) {}

    double distanceTo(const Location& other) const {
        double dx = x - other.x;
        double dy = y - other.y;

        return std::sqrt(dx * dx + dy * dy);
    }
};

#endif