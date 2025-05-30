#include <iostream>

using namespace std;

class PtrSoftcopy {
private:
    std::string* ps;
    int i;
    std::size_t* num; // Reference counter
public:
    PtrSoftcopy(const std::string& s = std::string()) :
        ps(new std::string(s)), i(0), num(new std::size_t(1)) {}

    PtrSoftcopy(const PtrSoftcopy& p) :
        ps(p.ps), i(p.i), num(p.num) { ++*num; } // Copy pointers, increment count

    PtrSoftcopy& operator=(const PtrSoftcopy& rhs) {
        if (this == &rhs) return *this;
        if (--*num == 0) { // Decrement current object's ref count
            delete ps;
            delete num;
        }
        ps = rhs.ps;        // Copy data from rhs
        i = rhs.i;
        num = rhs.num;
        ++*num;             // Increment rhs's ref count
        return *this;
    }

    ~PtrSoftcopy() {
        if (--*num == 0) { // If last user, clean up
            delete ps;
            delete num;
        }
    }
};

int main(){
    
    return 0;
}