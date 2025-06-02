#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>

class Point {
private:
     double x, y;

 public:
     Point(double newX, double newY) ;
	
     Point(const Point& p);

     double getX() const; 	
     double getY() const; 	

};

class Line{
private:
     Point p1, p2;
     double distance;

public:
     Line(Point xp1, Point xp2);
     Line(const Line& q);
     double getDistance() const;
};

#endif // POINT_H