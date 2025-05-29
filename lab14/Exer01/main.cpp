#include <iostream>
#include <string>
#include <exception> // For std::exception

// using namespace std; // Avoid in global scope

class MyException : public std::exception {
public:
    MyException(const std::string& msg) : m_msg(msg) {
        std::cout << "MyException::MyException - set m_msg to:" << m_msg << std::endl;
    }
    ~MyException() noexcept { // Destructors should generally be noexcept
        std::cout << "MyException::~MyException" << std::endl;
    }
    // what() should also be noexcept and marked override
    virtual const char* what() const noexcept override {
        std::cout << "MyException::what" << std::endl;
        return m_msg.c_str();
    }
    const std::string m_msg; // Better to make private and access via getter
};

void throwDerivedException() {
    std::cout << "throwDerivedException - thrown a derived exception" << std::endl;
    std::string exceptionMessage("MyException thrown");
    throw MyException(exceptionMessage); // Throw by value
}

void illustrateDerivedExceptionCatch() {
    std::cout << "illustrateDerivedExceptionsCatch - start" << std::endl;
    try {
        throwDerivedException();
    }
    // Warning: Base class catch block before derived class makes derived catch unreachable
    catch (const std::exception& e) { // Base class catch block
        std::cout << "illustrateDerivedExceptionsCatch - caught an std::exception, e.what:" << e.what() << std::endl;
    }
    // This catch block will never be executed because MyException will be caught by std::exception above
    catch (const MyException& e) { // Derived class catch block
        std::cout << "illustrateDerivedExceptionsCatch - caught a MyException, e.what::" << e.what() << std::endl;
    }
    std::cout << "illustrateDerivedExceptionsCatch - end" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "main - start" << std::endl;
    illustrateDerivedExceptionCatch();
    std::cout << "main - end" << std::endl;
    return 0;
}