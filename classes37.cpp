#include <iostream>
#include <string>
class Yogurt{
private:
    std::string m_flavour{"vanilla"};
public :
    void setFlavour(std::string_view flavour){
        m_flavour=flavour;
    }
    const std::string& getFlavour() const {return m_flavour;}
    void print()const
    {
        std::cout << "the yogurt has flavour " << m_flavour << "\n";
    }
};
int main (){
    Yogurt y{};
    y.setFlavour("cherry");
    y.print();
    return 0;
}
