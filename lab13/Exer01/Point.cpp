#include "Point.h"

Point::Point(double newX, double newY) : x(newX), y(newY) {}
Point::Point(const Point& p) : x(p.x), y(p.y) {}
double Point::getX() const {
     return x;
}
double Point::getY() const {
     return y;
}

Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2) {
     double dx = p2.getX() - p1.getX();
     double dy = p2.getY() - p1.getY();
     distance = sqrt(dx * dx + dy * dy);
}

Line::Line(const Line& q) : p1(q.p1), p2(q.p2), distance(q.distance) {}

double Line::getDistance() const {
     return distance;
}