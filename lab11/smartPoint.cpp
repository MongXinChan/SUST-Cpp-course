#include <memory>
#include <string>
#include <iostream>

class StringPtr {
private:
    std::shared_ptr<std::string> dataptr; // Smart pointer as a data member
    int i;
public:
    StringPtr(const std::string& s = std::string(), int m = 0) :
        dataptr(std::make_shared<std::string>(s)), i(m) {}

    friend std::ostream& operator<<(std::ostream& os, const StringPtr& str) {
        os << *str.dataptr << ", " << str.i;
        return os;
    }
};

int main(){
    
    return 0;
}