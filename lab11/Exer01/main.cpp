#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main(){
    
    /** 正常管理动态分配的double */
    //  使用 make_shared (recommand)
    shared_ptr<double> pd1=make_shared<double>(5.0);
    cout << "*pd1 = " << *pd1 << endl << endl;

    //  使用 new 和 shared_ptr 的构造函数 (确保原始指针不被滥用)
    double *p_raw_double = new double(10.0);
    shared_ptr<double> pd2(p_raw_double);
    //  pd 现在用拥有 p_raw_double
    // p_raw_double 不应该再被其他独立的 shared_ptr 初始化，或手动 delete

    // 如果要共享 pd2 的对象
    cout<< "pd2 use_count: " << pd2.use_count() << endl;        //输出应为1 
    shared_ptr<double> pd3=pd2;     // pd3 和 pd2 共享一个double(10.0)
    cout<< "*pd2 = " << *pd2 << ", *pd3 = "<< *pd3 <<endl;
    cout<< "pd3 use_count: " << pd3.use_count() << endl << endl;        //输出应为2 


    // --- 错误地用 shared_ptr 管理栈对象 ---
    // string str_stack("Hello Stack!");
    // shared_ptr<string> pstr_stack_error(&str_stack); // 这是错误的，会导致崩溃！
    // cout << "*pstr_stack_error = " << *pstr_stack_error << endl; // 不要这样做！
    

    // 正确管理动态分配的 string:
    shared_ptr<string> pstr_heap = std::make_shared<string>("Hello Heap!");
    cout << "*pstr_heap = " << *pstr_heap << endl << endl;

    string str("Hello World!");
    shared_ptr<string> pstr(&str); 
    cout << "*pstr = " << *pstr << endl << endl;

    // --- 避免你代码中 p_reg 的重复管理问题 ---
    // 原始的 p_reg 只能被一个 shared_ptr 初始化系列所拥有
    double *p_reg_original = new double(15.0);

    shared_ptr<double> sp_owner1(p_reg_original); // sp_owner1 获得所有权

    // 如果需要另一个 shared_ptr 指向同一个对象，从 sp_owner1 拷贝：
    shared_ptr<double> sp_owner2 = sp_owner1;

    // 不要这样做：
    // shared_ptr<double> sp_owner_error(p_reg_original); // 错误！这会导致 p_reg_original 被重复管理

    cout << "*sp_owner1 = " << *sp_owner1 << endl;
    cout << "*sp_owner2 = " << *sp_owner2 << endl;
    cout << "sp_owner1 use_count: " << sp_owner1.use_count() << endl;


    return 0;
}
