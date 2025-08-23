#include <iostream>
#include <string>
#include <string_view>
class Person{
    private:
        std::string m_name{};
    public:
        void kills(const Person&p)const
        {
            std::cout << m_name << " kills " << p.m_name << "\n";
        }
        void setName(std::string_view name){
            m_name=name;
        }
};
int main (){
    Person joe;
    joe.setName("Joe");
    Person kate;
    kate.setName("Kate");
    joe.kills(kate);
    return 0;
}
