#include <iostream>
#ifndef __MYSTRING__
#define __MYSTRING__

class String{
private:
    char * m_data;

public:
    String(const char* cstr=0);

    ~String(){
        std::cout<< "Constructor function: \"" << m_data << "\" Done." <<std::endl;
        delete[] m_data;
    }

    String(const String& str);

    String& operator=(const String& str);

    char& operator[](std::size_t position){
        return m_data[position];
    }

    const char& operator[](std::size_t position) const{
        return m_data[position];
    }

    char* get_c_str() const{
        return m_data;
    }

    friend std::ostream& operator<<(std::ostream& os,const String& str);
};

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.m_data; // 直接访问私有成员 m_data
    return os;
}

#endif //String.h   主要是重载了两个get方法，可以得到const和non-const[]的版本