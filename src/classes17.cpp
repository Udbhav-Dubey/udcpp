#include <iostream>
class Foe{
    public:
        void print() const
        {
            std::cout << m_year << "/" << m_month << "/" << m_day;
        }
    private:
        int m_something{};
        int m_year{2020};
        int m_month{14};
        int m_day{10};
};
int main (){
    Foo d{};
    d.print();
    return 0;
}
