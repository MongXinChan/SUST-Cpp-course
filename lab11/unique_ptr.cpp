#include <memory> // Required for smart pointers
#include <string>
#include <iostream>

int main(){
    // unique_ptr with a single object
    std::unique_ptr<int> up1(new int(9));
    std::cout << "up1's content: " << *up1 << std::endl;

    // Using make_unique (preferred)
    std::unique_ptr<std::string> up3 = std::make_unique<std::string>("Hello world!");
    std::cout << "up3's contents: " << *up3 << std::endl;

    // unique_ptr for an array
    std::unique_ptr<int[]> up4 = std::make_unique<int[]>(5); // Array of 5 ints
    for (int i = 0; i < 5; ++i) up4[i] = i * 10;

    // Transferring ownership
    std::unique_ptr<int> up6 = std::move(up1);
    std::cout << "up6's content: " << *up6 << std::endl;
    std::cout << "up1 is now " << (up1 ? "not null" : "null") << std::endl; // up1 is now null

    return 0;
}