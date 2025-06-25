#include <iostream>
#include <limits>
using namespace std;

class RangeError {
private:
    int val;
public:
    RangeError(int v) : val(v) {}
    int getValue() const { return val; }
};

char to_char(int n){
    if(n < numeric_limits<char>::min() || n > numeric_limits<char>::max()) {
        throw RangeError(n);
    }
    return (char)n;
}

void gain(int n){
    try{
        char c = to_char(n);
        cout << "The character representation of " << n << " is: " << c << endl;
    } catch (const RangeError& e) {
        cerr << "RangeError: Value " << e.getValue() << " is out of range for char type." << endl;
        cerr << "Range is" << (int) numeric_limits<char>::min() << " to " 
             << (int) numeric_limits<char>::max() << endl;
    } catch (...) {
        cerr << "An unexpected error occurred." << endl;
    }
}

int main(){
    gain(-130);

    return 0;
}