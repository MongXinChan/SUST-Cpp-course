#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream> // For std::cout in display method and displayCircle function

class Circle {
private:
    double radius;

public:
    // Converting constructor: double -> Circle
    // Allows implicit conversion from a double to a Circle object.
    Circle(double r);

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
// This function can take a Circle object by value,
// potentially utilizing the converting constructor if a double is passed.
void displayCircle(Circle c);

#endif // CIRCLE_H