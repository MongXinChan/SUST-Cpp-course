#ifndef CAR_H
#define CAR_H

#include <iostream>

class Driver; // Forward declaration
class Car {
private:
    enum {Off, On}; // Off - non-automatic drive, On - automatic drive
    enum {Minvel = 0, Maxvel = 200}; // Velocity range
    int mode;     // Car mode, Off or On
    int velocity;
public:
    friend class Driver; // Driver is a friend of Car
    Car(int m = On, int v = 50):mode(m),velocity(v){}
    bool velup(int v);   // Increase velocity by v
    bool veldown(int v); // Decrease velocity by v
    bool ison() const;   // Check if mode is On
    int getvel() const;  // Get velocity
    void showinfo() const; // Show car's mode and velocity
};

#endif //Car.h