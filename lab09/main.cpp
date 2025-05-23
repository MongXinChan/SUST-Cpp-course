#include <iostream>
#include "Box.h"

using namespace std;

int main(){

    Box first(5.0, 6.0, 9.0); // Calls parameterized constructor
    Box second(3.2,3.3,4.4);            // Implicitly calls default constructor
    Box third = Box();      // Explicitly calls default constructor
    Box *pbox = new Box;     // Dynamically creates object, implicitly calls default constructor

    //Box fourth();     Error classic mistake, declares a function

    cout<< "The address of second box is: " << &second << endl;
    Box fourth=second;
    cout<< "The address of fourth box is: " << &fourth << endl;

    if(&fourth==&second){
        cout<< "The address of second box is the same as the address of fourth box." << endl;
    }else{
        cout<< "The address of second box is different from the address of fourth box." << endl;
    }

    if(fourth.getVolume() == second.getVolume()){
        cout<< "The volume of second box is the same as the volume of fourth box." << endl;
    }else{
        cout<< "The volume of second box is different from the volume of fourth box." << endl;
    }

    // = 值拷贝 



    cout << "Volume of first box: " << first.getVolume() << endl;

    cout << "Volume of pbox: " << pbox->getVolume() << endl;
    delete pbox; // Free dynamically allocated memory

    return 0;
}