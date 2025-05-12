#include <iostream> // Or other necessary includes like <string> or <cstdio>
#include <string>   // Needed if stuinfo::name is std::string

// --- STEP 1: Define the struct stuinfo ---
// The full definition must come BEFORE the function that uses its members.
struct stuinfo {
    int age;          // Example member
    std::string name; // Example member (use std::string or char* as appropriate)
    // Any other members...
};

// --- STEP 2: (Optional) Define the generic template if you have one ---
// If you only have the specialization, you might not need this.
template<typename T>
int Compare(const T& a, const T& b) {
    // Default comparison logic for other types (if any)
    std::cout << "Using generic Compare template" << std::endl;
    if (a < b) return -1;
    if (b < a) return 1;
    return 0;
}


// --- STEP 3: Define the TEMPLATE SPECIALIZATION for stuinfo ---
// Make sure the struct definition above is already seen by the compiler.
// Use template<> to indicate specialization.
template<>
int Compare<stuinfo>(const stuinfo& a, const stuinfo& b) {
    // Now the compiler knows stuinfo has members 'age' and 'name'.
    if (a.age > b.age) {
        return 1;
    } else if (a.age < b.age) {
        return -1;
    } else {
        // Ages are equal, compare by name
        if (a.name > b.name) {
            return 1;
        } else if (a.name < b.name) {
            return -1;
        } else {
            return 0; // Both age and name are equal
        }
    }
}


// --- STEP 4: Your main function or other code using Compare ---
int main() {
    stuinfo s1 = { 20, "Charlie" };
    stuinfo s2 = { 22, "Bob" };
    stuinfo s3 = { 20, "Alice" };

    // These calls will use the specialized Compare<stuinfo> function
    int result1 = Compare(s1, s2); // Calls Compare<stuinfo>
    int result2 = Compare(s1, s3); // Calls Compare<stuinfo>

    std::cout << "Compare(s1, s2): " << result1 << std::endl; // Expected: -1 (s1.age < s2.age)
    std::cout << "Compare(s1, s3): " << result2 << std::endl; // Expected: -1 (s1.age == s3.age, s1.name < s3.name)

    // Example of calling the generic template (if defined)
    // int x = 10, y = 5;
    // std::cout << "Compare(x, y): " << Compare(x, y) << std::endl;

    return 0;
}