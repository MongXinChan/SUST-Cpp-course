#include <iostream>
#include <memory>

// 前向声明 Class B
class B;

class A {
public: // 修改为 public
    std::shared_ptr<B> pb;
    A() {
        std::cout << "Constructor A" << std::endl;
    }
    ~A() {
        std::cout << "Destructor A" << std::endl;
    }
};

class B {
public:
    std::shared_ptr<A> pa;
    B() {
        std::cout << "Constructor B" << std::endl;
    }
    ~B() {
        std::cout << "Destructor B" << std::endl;
    }
};

int main() {
    std::cout << "--- Creating objects ---" << std::endl;
    std::shared_ptr<A> spa = std::make_shared<A>();
    std::shared_ptr<B> spb = std::make_shared<B>();

    std::cout << "--- Creating circular reference ---" << std::endl;
    spa->pb = spb; // A points to B, B's ref count becomes 2
    spb->pa = spa; // B points to A, A's ref count becomes 2

    std::cout << "--- spa use_count: " << spa.use_count() << std::endl; // A's ref count
    std::cout << "--- spb use_count: " << spb.use_count() << std::endl; // B's ref count

    std::cout << "--- main function ends ---" << std::endl;
    // spa goes out of scope, A's ref count becomes 1 (due to spb->pa)
    // spb goes out of scope, B's ref count becomes 1 (due to spa->pb)
    // Destructors A and B will NOT be called.
    return 0;
}