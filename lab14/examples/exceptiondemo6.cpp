#include <iostream>
using namespace std;

class MyException : public exception {
public:
    virtual const char* what() const noexcept override {
        return "Cpp Exception.";
    }
};

int main(){
    try {
        throw MyException();
    } catch (const MyException& e) {
        cout << "Base class exception is caught:" << e.what() << endl;
        cout << e.what() << endl;
    }
    return 0;
}