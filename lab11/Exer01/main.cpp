#include <iostream>
#include <memory>
using namespace std;
int main()
{
    double *p_reg = new double(5);
    shared_ptr<double> pd;
    pd = p_reg;         
    pd = shared_ptr<double>(p_reg); 
    cout << "*pd = " << *pd << endl;


    shared_ptr<double> pshared = p_reg; 
    shared_ptr<double> pshared(p_reg); 
    cout << "*pshred = " << *pshared << endl;

    
    string str("Hello World!");
    shared_ptr<string> pstr(&str); 
    cout << "*pstr = " << *pstr << endl;

    return 0;
}
