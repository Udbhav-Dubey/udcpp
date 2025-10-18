#include <iostream>
#include <string>
#include <string_view>
class Employee{
private:
    std::string m_name{};
public :
    void setName(std::string_view name){m_name=name;}
    const std::string& getName() const{return m_name;}
};
Employee createEmployee(std::string_view name){
    Employee e;
    e.setName(name);
    return e;
}
int main (){
    std::cout << createEmployee("Frank").getName() << std::endl; 
    const std::string&ref{createEmployee("Garbo").getName()};
    std::cout << ref << std::endl;
    std::string val{createEmployee("Hans").getName()};
    std::cout << val << std::endl;
return 0;
}
