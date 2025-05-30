#include <memory>
#include <iostream>

class MyData {
    int val;
public:
    MyData(int v) : val(v) { std::cout << "MyData Constructor(" << val << ")" << std::endl; }
    ~MyData() { std::cout << "MyData Destructor(" << val << ")" << std::endl; }
    int getVal() const { return val; }
};

int main(){

    std::shared_ptr<MyData> sp1 = std::make_shared<MyData>(100);
    std::cout << "sp1 data: " << sp1->getVal() << ", use_count: " << sp1.use_count() << std::endl;

    std::shared_ptr<MyData> sp2 = sp1; // Copying, increments use_count
    std::cout << "sp1 data: " << sp1->getVal() << ", use_count: " << sp1.use_count() << std::endl;
    std::cout << "sp2 data: " << sp2->getVal() << ", use_count: " << sp2.use_count() << std::endl;

    return 0;
}