// lib_src/swap_lib.cpp

// This function's implementation will go into libswap.a
void swap_integers(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}