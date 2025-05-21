#include<iostream>
using namespace std;
class Demo{
    private:
        int id;
        void display(){
        cout<<"this is: "<<this<<", id is:"<<this->id<<endl;
        }
    public :
        Demo(int cid){
        this->id=cid;
        }
    static int num; 
    void display()
    {
        cout<<"The value of the static num is: "<<num<<endl;
    }
}; 
int main() 
{
  Demo obj;
  Demo obj1(1);

  obj.display();
  obj1.display();

  Demo::display();

  return 0;
}
