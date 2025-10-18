#include<iostream>
#include<string>
class Employe{
    std::string m_name{};
public:
    void setName(std::string_view name){m_name=name;}
    const auto &getName()const {return m_name;} 
};
int main (){
    Employe joe{};
    joe.setName("joey");
    std::cout<<joe.getName();
    return 0;
}
