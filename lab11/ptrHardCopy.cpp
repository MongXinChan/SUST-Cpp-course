#include<iostream>

using namespace std;

class PtrHardcopy {
private:
    std::string* ps;
    int i;
public:
    PtrHardcopy(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}
    // Copy constructor (deep copy)
    PtrHardcopy(const PtrHardcopy& p) : ps(new std::string(*p.ps)), i(p.i) {}
    // Assignment operator (deep copy)
    PtrHardcopy& operator=(const PtrHardcopy& rhs) {
        if (this == &rhs) return *this; // Handle self-assignment
        delete ps;                      // Free old resource
        ps = new std::string(*rhs.ps);  // Allocate new and copy
        i = rhs.i;
        return *this;
    }
    ~PtrHardcopy() { delete ps; }
};

int main(){
    
    return 0;
}