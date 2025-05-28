#ifndef EXPLICIT_CIRCLE_H
#define EXPLICIT_CIRCLE_H

#include <iostream> // For std::cout in display method and displayCircle function

class Circle {
private:
    double radius;

public:
    // Explicit converting constructor: double -> Circle
    // The 'explicit' keyword prevents implicit conversions from double.
    explicit Circle(double r);

    // Default constructor
    // Initializes a circle with a default radius of 1.0.
    Circle();

    // Getter for radius
    double getRadius() const;

    // Setter for radius
    void setRadius(double r);

    // Member function to display circle information
    void display() const;
};

// Declaration of the free function to display a Circle object
void displayCircle(Circle c);

#endif //  EXPLICIT_CIRCLE_H