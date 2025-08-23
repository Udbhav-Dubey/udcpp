#include <iostream>
class Date{
    int m_year{};
    int m_month{};
    int m_day{};
    void print() const{
        std::cout << m_year << "/" << m_month << "/" << m_day;
    }
};
int main (){
    Date today{2020,10,14};
    today.m_day=16;
    today.print();
    return 0;
}
