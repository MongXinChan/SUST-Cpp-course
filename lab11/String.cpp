#include <iostream>
#include "String.h"
#include <cstring>

String::String(const char* cstr) {
    if (cstr == nullptr) {
        m_data = new char[1]; // 分配内存给空终止符
        m_data[0] = '\0';     // 创建一个空字符串
    } else {
        m_data = new char[std::strlen(cstr) + 1]; // 为字符串和空终止符分配内存
        std::strcpy(m_data, cstr);                // 复制内容
    }
}

String::String(const String& other) { // 拷贝构造函数
    m_data = new char[std::strlen(other.m_data) + 1];
    std::strcpy(m_data, other.m_data);
}

String& String::operator=(const String& other) { // 拷贝赋值运算符
    if (this == &other) { // 处理自赋值
        return *this;
    }
    delete[] m_data; // 释放旧资源
    m_data = new char[std::strlen(other.m_data) + 1];
    std::strcpy(m_data, other.m_data);
    return *this;
}


int main(){

    String s1("hello");
    const String s2("world");
    std::cout << "s1[0]:" << s1[0] << ",s2[0]:" << s2[0]<< std::endl;

    char a=s1[1];
    char b=s2[2];

    std::cout<< "a:" << a << ",b: " << b <<std::endl;

    s1[0]='x';

//  s2[0]='Z';  //Error const无法修改

    std::cout << "s2:" << s2 << std::endl;
    std::cout << "s1:" << s1 << std::endl;

    std::cout << "The Main Process Done." << std::endl;

    return 0;
}