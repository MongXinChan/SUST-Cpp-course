#include "explicit_circle.h" // Include the header file
#include <iostream>  // For std::cout and std::endl

// Explicit converting constructor definition
Circle::Circle(double r) : radius(r) {
    std::cout << "Explicit constructor called: Circle(" << r << ") created." << std::endl;
}

// Default constructor definition
Circle::Circle() : radius(1.0) {
    std::cout << "Default constructor called: Circle with radius 1.0 created." << std::endl;
}

// Getter for radius definition
double Circle::getRadius() const {
    return radius;
}

// Setter for radius definition
void Circle::setRadius(double r) {
    if (r >= 0) { // Radius should be non-negative
        radius = r;
    } else {
        std::cout << "Error: Radius cannot be negative. Radius not changed." << std::endl;
    }
}

// Member function to display circle information definition
void Circle::display() const {
    std::cout << "Circle - Radius: " << radius << std::endl;
}

// Definition of the free function to display a Circle object
void displayCircle(Circle c) {
    std::cout << "Displaying Circle via free function - Radius: " << c.getRadius() << std::endl;
}

int main() {
    std::cout << "--- Demonstrating 'explicit' constructor effects ---" << std::endl;

    // displayCircle(10.5); // ERROR! Cannot perform implicit conversion due to 'explicit'
                          // Uncommenting this line will cause a compilation error.
    std::cout << "Attempting 'displayCircle(10.5);' would cause a compile error." << std::endl;

    // Circle c1 = 20;    // ERROR! Cannot perform implicit conversion (copy-initialization)
                          // due to 'explicit'.
                          // Uncommenting this line will cause a compilation error.
    std::cout << "Attempting 'Circle c1 = 20;' would cause a compile error." << std::endl;

    std::cout << "\n--- Valid ways to initialize with 'explicit' constructor ---" << std::endl;

    std::cout << "1. Direct initialization:" << std::endl;
    Circle c2(10.5);      // OK: Direct initialization is always allowed.
    c2.display();

    std::cout << "\n2. Explicit conversion then copy/move-initialization:" << std::endl;
    Circle c3 = Circle(20.0); // OK: Explicitly creating a Circle object, then using it
                              // for initialization. (double 20.0 -> Circle(20.0))
    c3.display();
    // Note: int 20 would be promoted to double 20.0 for the Circle(20.0) constructor.

    std::cout << "\n3. Using static_cast for explicit conversion:" << std::endl;
    Circle c4 = static_cast<Circle>(30.0); // OK: Explicit cast.
    c4.display();

    std::cout << "\n--- Using displayCircle with explicitly created/converted Circle objects ---" << std::endl;
    // To use displayCircle, you must pass a Circle object:
    displayCircle(Circle(15.5)); // OK: Explicitly create a temporary Circle object
    displayCircle(c2);           // OK: Pass an existing Circle object

    std::cout << "\n--- Demonstrating default constructor ---" << std::endl;
    Circle c5;
    c5.display();

    std::cout << "\n--- Setting a new radius ---" << std::endl;
    c2.setRadius(7.0);
    c2.display();

    return 0;
}