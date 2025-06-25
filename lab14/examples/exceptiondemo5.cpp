#include <iostream>
using namespace std;

class MyException : public exception {
public:
    const char* what() const noexcept override {
        return "Cpp Exception.";
    }
};

int main(){
    try {
        throw MyException();
    } catch (const MyException& e) {
        cout << "Caught MyException: " << e.what() << endl;
        cout << e.what() << endl;
    } catch (const exception& e) {
        cout << "Caught a general exception: " << e.what() << endl;
    } catch (...) {
        cout << "Caught an unknown exception." << endl;
    }
    return 0;
}