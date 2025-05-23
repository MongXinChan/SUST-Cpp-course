#include <iostream>
#include "const_member.h"

using namespace std;

int main(){
    Myclass obj(10); // Create an object of MyClass

    obj.show_x(); // Call the member function to display the value of x

    return 0; // Return 0 to indicate successful completion
}