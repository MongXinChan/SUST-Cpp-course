#include "Box.h"

//Implementation of  functions using the scope resolution operator(::)


Box::Box(){ // Default constructor
    length = 1;
    width = 1;
    height = 1;
}
Box::Box(double l, double w, double h){ // Constructor with parameters
    this->length = l;
    this->width = w;
    this->height = h;
}

double Box::getVolume(){ // Function to calculate volume
    return length * width * height;
}

void Box::setLength(double l){ // Function to set length
    this->length = l;
}

void Box::setWidth(double w){ // Function to set width
    this->width = w;
}

void Box::setHeight(double h){ // Function to set height
    this->height = h;
}
