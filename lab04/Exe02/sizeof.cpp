#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int cards[4]{};
    int hands[4];
    float price[] = {2.8,3.7,5,9,'C', 'D'}; 
    char direction[]= {'L',82,'U',68,'\0'};
    char title[] = "DeepSeek is an awesome tool.";   
    cout << "sizeof(cards) = " << sizeof(cards) << ",sizeof of cards[0] = " << sizeof(cards[0]) << endl;
    cout << "sizeof(price) = " << sizeof(price) << ",sizeof of price[0] = " << sizeof(price[0]) << endl;
    cout << "sizeof(direction) = " << sizeof(direction) << ",length of direction = " << strlen(direction) << endl;
    cout << "sizeof(title) = " << sizeof(title) << ",length of title = " << strlen(title) << endl;

    return 0;
}
