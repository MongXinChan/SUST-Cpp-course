#include <iostream>

class Engine {
public:
    Engine(int nc) : cylinder(nc) { std::cout << "Constructor:Engine(int)\n"; }
    void start() { std::cout << getCylinder() << " cylinder engine started\n"; }
    int getCylinder() { return cylinder; }
    ~Engine() { std::cout << "Destructor:~Engine()\n"; }
private:
    int cylinder;
};

class Car {
private:
    Engine eng; // Car "has-an" Engine
public:
    Car(int n = 4) : eng(n) { std::cout << "Constructor:Car(int)\n"; } // Initialize member object via initializer list
    void start() {
        std::cout << "car with " << eng.getCylinder() << " cylinder engine started\n";
        eng.start();
    }
    ~Car() { std::cout << "Destructor:~Car()\n"; }
};

int main(){
    Car c1;
    c1.start();
    
    std::cout<< "End of main\n";

    return 0;
}