#include<iostream>
using namespace std;

int main(){
    string str;
    cout<<"Enter a string:";
    getline(cin, str);
    cout<<"Your string is: "<<str<<endl;

    cout<<"Enter another string:";
    getline(cin, str);
    cout<<"Your string is: "<<str<<endl;
    
    return 0;
}