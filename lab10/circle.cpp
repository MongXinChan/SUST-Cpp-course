#include "circle.h" // Include the header file
#include <iostream>  // For std::cout and std::endl

// Converting constructor definition
Circle::Circle(double r) : radius(r) {
    std::cout << "Converting constructor called: Circle(" << r << ") created." << std::endl;
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

// Example main function to demonstrate usage (optional, can be in a separate main.cpp)

int main() {
    std::cout << "--- Demonstrating implicit conversion with function call ---" << std::endl;
    displayCircle(10.5); // Implicit conversion: 10.5 (double) converted to Circle(10.5)

    std::cout << "\n--- Demonstrating implicit conversion with initialization ---" << std::endl;
    Circle c1 = 20;       // Implicit conversion: 20 (int, promoted to double) converted to Circle(20.0)
    c1.display();

    std::cout << "\n--- Demonstrating default constructor ---" << std::endl;
    Circle c2;
    c2.display();

    std::cout << "\n--- Demonstrating converting constructor explicitly ---" << std::endl;
    Circle c3(5.5);
    c3.display();

    std::cout << "\n--- Using displayCircle with an existing Circle object ---" << std::endl;
    displayCircle(c3);

    std::cout << "\n--- Setting a new radius ---" << std::endl;
    c3.setRadius(7.0);
    c3.display();

    c3.setRadius(-2.0); // Attempt to set an invalid radius
    c3.display();


    return 0;
}
