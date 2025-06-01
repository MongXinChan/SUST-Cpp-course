#include <iostream>


class Base
{
private:
    int x;
protected:
    int y;
public:
    int z;
    void funBase(Base& b) {
        ++x; ++y; ++z;
        ++b.x; ++b.y; ++b.z; // Base object can access private/protected members of another Base object
    }
};

class Derived : public Base {
public:
    void funDerived(Base& b, Derived& d) {
        // ++x;       // Error: x is private in Base
        ++y;       // OK: y is protected in Base, Derived is a subclass
        ++z;       // OK: z is public in Base
        // ++b.x;     // Error: Cannot access private member x of arbitrary Base object b
        // ++b.y;     // Error: Cannot access protected member y of arbitrary Base object b (unless Derived is a friend of b)
        ++b.z;     // OK: Can access public member z of arbitrary Base object b
        // ++d.x;     // Error: x is private in Base
        ++d.y;     // OK: d is a Derived object, can access its inherited protected member y
        ++d.z;     // OK: d is a Derived object, can access its inherited public member z
    }
};

void fun(Base& b, Derived& d) {
    // ++x; ++y; ++z; // Error: Non-member function cannot directly access members of any class
    // ++b.x; ++b.y;   // Error: Cannot access private or protected members of Base object b
    ++b.z;           // OK
    // ++d.x; ++d.y;   // Error: Cannot access private or protected members of Derived object d (x is Base's private, y is Base's protected)
    ++d.z;           // OK
}

