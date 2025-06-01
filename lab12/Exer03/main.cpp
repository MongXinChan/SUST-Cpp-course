// dynamic allocation and polymorphism
#include <iostream>
using namespace std;
class Polygon 
{
protected:
    int width, height;
public:
    Polygon (int a, int b) : width(a), height(b) {}
    //Pure virtual function for area calculation
    virtual int area (void) =0;
    void printarea(){
        cout << this->area() << '\n';
    }
    virtual ~ Polygon() {
        cout << "Polygon destructor called" << endl;
        // Note: Do not delete 'this' here, as it will lead to undefined behavior.
    }
};

class Rectangle: public Polygon {
public:
    Rectangle(int a,int b) : Polygon(a,b) {}
    int area() override{
        return width*height;
    }
    ~Rectangle() override { // 'override' is good practice
        std::cout << "Rectangle destructor called" << std::endl;
        // DO NOT 'delete this;' HERE!
    }
};

class Triangle: public Polygon {
  public:
    Triangle(int a,int b) : Polygon(a,b) {}
    int area() override{
        return width*height/2;
    }
    // Triangle destructor (optional if no specific resources, but good for consistency)
    ~Triangle() override { // 'override' is good practice
        std::cout << "Triangle destructor called" << std::endl;
    }
};


int main () {
    Polygon * ppoly1 = new Rectangle (4,5);
    std::cout << "Area of ppoly1 (Rectangle): ";
    ppoly1->printarea();
    delete ppoly1;  //now correctly calls ~Rectangle destructor then ~Polygon destructor

    std::cout << "------------------" << std::endl;

    Polygon * ppoly2 = new Triangle (2,5);
    std::cout << "Area of ppoly2 (Triangle): ";
    ppoly2->printarea();
    delete ppoly2;  //now correctly calls ~Triangle() destructor then ~Polygon() destructor

    return 0;
}
