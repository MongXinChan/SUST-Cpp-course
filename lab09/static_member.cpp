#include <iostream>
#include "static_member_function.h"

using namespace std;

int main(){
    StaticTest t;

    cout<<"Invoke static member function by object: "<<endl;
    
    cout<<"The value of the static member varible is:"<<t.getValue()<<endl;

    cout<<"Invoke static member function by class name: "<<endl;

    cout<<"The value of the static member varible is:"<<StaticTest::getValue()<<endl;

    return 0;
    
}