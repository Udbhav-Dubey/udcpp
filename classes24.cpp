#include <iostream>
class Date{
public :
    void print()const{
        std::cout << m_year << "/" << m_month << "/" << m_day ;
    }
private:
    int m_year{2020};
    int m_month{14};
    int m_day{10};
};
int main (){
    Date d{};
    d.print();
    return 0;
}
