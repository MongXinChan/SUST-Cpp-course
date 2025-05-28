#include <iostream>   //MyTime.cpp
class MyTime{
    int hours;
    int minutes;
public:
    MyTime(): hours(0), minutes(0){}
    MyTime(int h, int m): hours(h), minutes(m){}
    MyTime operator+(int m) const{
        MyTime sum;
        sum.minutes=this->minutes+m;
        sum.hours=this->hours;
        sum.hours+=sum.minutes/60;
        sum.minutes%=60;
        return sum;
    }
    friend MyTimeoperator+(int m, const MyTime&t){
        return t+m;
    }
    friend std::ostream& operator<<(std::ostream&os, const MyTime&t){
        std::string str=std::to_string(t.hours) +" hours and "
                +std::to_string(t.minutes) +" minutes.";
        os<<str;
        return os;
    }
};
int main(){
    MyTime mt(1,59);
    std::cout<<mt+2<<std::endl;
    std::cout<<1+mt<<std::endl;
    return 0;
}
