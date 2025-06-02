#include <iostream>
#include <cmath>
#include "Point.h"

int main(){
     Point a(8, 9),b(1,2);
     Point c = a;
     std::cout << "point a: x = " << a.getX() << ", y = " << a.getY() << std::endl;
     std::cout << "point b: x = " << b.getX() << ", y = " << b.getY() << std::endl;
     std::cout << "point c: x = " << c.getX() << ", y = " << c.getY() << std::endl;

     std::cout << "------------------------------------------" << std::endl;
     Line line1(a, b);
     std::cout << "line1's distance:" << line1.getDistance() << std::endl;

     Line line2(line1);
     std::cout << "line2's distance:" << line2.getDistance() << std::endl;

     std::cout << "------------------------------------------" << std::endl;

     return 0;
}
