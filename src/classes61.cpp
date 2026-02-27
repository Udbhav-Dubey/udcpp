#include <iostream>
class Base{
    public:
        int id{};
    Base(int i=0): id{i}{
        std::cout << "Base constructor\n";
    }
    int getId()const{return id;}
};
class Derived:public Base{
    public:
        double cost{};
        Derived(double c=0.0,int d=0): Base{d},cost{c}{
            std::cout << "Derived constructor\n";
        };
        double getCost()const {return cost;}
};
int main (){
    Derived der{1.3,5};
    std::cout << "Id " << der.getId() << "\n";
    std::cout << "Cost " << der.getCost() << "\n";
    return 0;
}
