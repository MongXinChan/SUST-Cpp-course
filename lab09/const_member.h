#include <iostream>

using namespace std;

class MyClass {
private:
    const int x; // const member variable
public:
    MyClass(int a) : x(a) { // Initialize const member via initializer list
        // constructor body
    }
    void show_x() {
         std::cout << "Value of constant x: " << x;
    }
};

class Person{
private:
    static const int Len=30;
    //enum {Len=30};
    char name[Len];

public:
    Person():name{"Zhangsan"}{
    }

    void display();
};