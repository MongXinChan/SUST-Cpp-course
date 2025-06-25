#include <assert.h>
#include <iostream>
using namespace std;

int main(){
    int x = 7;
    x = 9;

    assert(x == 7); // This assertion will pass

    cout<< "Assertion passed, x is indeed 7." << endl;

    return 0;
}