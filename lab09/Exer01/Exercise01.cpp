#include<iostream>
using namespace std;
class Demo{
private:
    int id;
public :
    Demo() : id(0){
        cout<<"Default constructor called"<<endl;
    }
    Demo(int cid){
        this->id=cid;
        cout<<"Parameterized constructor called"<<endl;
    }
    static int num; 
    static void display(){
        cout<<"The value of the static num is: "<<num++<<endl;
        // Note: A static function cannot access non-static members like 'this->id'
    }
};

int Demo::num = 10; // Definition and initialization of static member variable

int main() 
{
    Demo obj;
    Demo obj1(1);

    obj.display();
    obj1.display();

    Demo::display();

    return 0;
}
