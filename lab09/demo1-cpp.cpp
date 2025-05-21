#include <iostream>      //C++ Code
#include <cstring>
using namespace std;
class vsdemo{
private:
    const int length;
    char *name;
    static int classId;
public:
    vsdemo(int len,char* nm):length(len){
        name=new char[length];
            if(NULL!=name){
                strncpy(name,nm,length-1);
                name[length-1]='\0';
        }
    }
    ~vsdemo(){
    if(NULL!=name){
        delete[](name);
        cout<<"~vsdemo"<<endl;
    }
}
void disObj(){
        cout<<"Ojb address: "<<this
    <<", length:"<<length<<", name: "<<name<<endl;
    }
static void displayClassId(){
        cout<<"classId: "<<classId<<endl;
    }
};
int vsdemo::classId=2025;
int main(){
    char tdata[14]="SUSTECH_CS219";
    vsdemo vsd1(sizeof(tdata),tdata);
    vsdemo::displayClassId();
    vsd1.disObj();
    return 0;
}
