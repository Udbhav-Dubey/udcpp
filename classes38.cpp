#include <iostream>
#include <string>
class Yogurt{
    std::string m_flavor{"Vanila"};
public:
    void setFlavor(std::string_view flavor){
        m_flavor=flavor;
    }
    const std::string& getFlavor()const{return m_flavor;}
    void print(std::string_view prefix)const{
        std::cout << prefix << ' ' << getFlavor() << std::endl;
    }
};
int main (){
    Yogurt y{};
    y.setFlavor("cherry");
    y.print("the yogurt has flavor ");
    return 0;
}
