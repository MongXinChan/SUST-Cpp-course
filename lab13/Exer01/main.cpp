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


int main(){
      Point a(8, 9),b(1,2);
      Point c = a;
      cout << "point a: x = " << a.getX() << ", y = " << a.getY() << endl;
      cout << "point b: x = " << b.getX() << ", y = " << b.getY() << endl;
      cout << "point c: x = " << c.getX() << ", y = " << c.getY() << endl;

      cout << "------------------------------------------" << endl;
      Line line1(a, b);
      cout << "line1's distance:" << line1.getDistance() << endl;

      Line line2(line1);
     cout << "line2's distance:" << line2.getDistance() << endl;

     return 0;
}
