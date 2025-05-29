#ifndef DRIVER_H
#define DRIVER_H

#include "Car.h"

class Driver {
public:
    bool velup(Car& car, int v);   // Increase velocity by v
    bool veldown(Car& car, int v); // Decrease velocity by v
    void setmode(Car& car);        // If mode is On, set to Off, otherwise set to On
    bool ison(Car& car) const;     // Check if mode is On
};

#endif //Driver.h