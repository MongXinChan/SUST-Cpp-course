#include<iostream>
using namespace std;

class Polygon{
protected:
    int width,height;
public:
    void set_values(int a,int b){
        width=a;
        height=b;
    }
    // Make area() virtual to enable polymorphism
    // Option 1: Virtual function with a default implementation (though often less useful for abstract concepts)
    // virtual int area() {
    //     std::cout << "Polygon::area() called - should be overridden" << std::endl;
    //     return 0;
    // }

    // Option 2: Pure virtual function, making Polygon an abstract class
    virtual int area() = 0;
    
    virtual ~Polygon() {
        // 虚析构函数，确保正确释放资源
        std::cout << "Polygon destructor called" << std::endl;
    }

    //// If Polygon were to manage its own dynamic resources, they would be cleaned up here.
};

class Rectangle: public Polygon {
public:
    int area() override{ 
        return width * height;
    }

    ~Rectangle() {
        std::cout << "Rectangle destructor called" << std::endl;
    }
};

class Triangle: public Polygon {
public:
    int area() override{ 
        return width*height/2; 
    }
    ~Triangle() {
        std::cout << "Triangle destructor called" << std::endl;
    }
};

int main () {
    Rectangle rect;
    Triangle trgl;
    Polygon * ppoly1 = &rect;
    Polygon * ppoly2 = &trgl;
    ppoly1->set_values (4,5);
    ppoly2->set_values (2,5);

    std::cout << rect.area() << std::endl;
    std::cout << trgl.area() << std::endl;
    std::cout << ppoly1->area() << std::endl;
    std::cout << ppoly2->area() << std::endl;
    std::cout << "-- End of main, objects going out of scope ---" << (dynamic_cast<Rectangle*>(ppoly1) != nullptr) << std::endl;
  return 0;
}
