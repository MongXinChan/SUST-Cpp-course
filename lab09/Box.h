#ifndef BOX_H
#define BOX_H

#include <iostream>


class Box{
private:
    double length;
    double width;
    double height;
public:
    Box();

    Box(double l, double w, double h);// Constructor with parameters
    //Box(double,double,double); NOT write the variable names

    //Member function declaration
    double getVolume(); // Function to calculate volume

    void setLength(double l); // Function to set length
    void setWidth(double w); // Function to set width
    void setHeight(double h); // Function to set height

};

#endif