#include <iostream>
class Simple{
    private:
        int m_id{};
    public:
        Simple(int id):m_id{id}{};
        int getId()const{return m_id;}
        void setId(int id){m_id=id;}
        void print()const {std::cout << this->m_id;}
};
int main (){
    Simple simple{1};
    simple.setId(2);
    simple.print();
    return 0;
}
