#include <iostream>
#include<string>
struct Employee{
    std::string name{"John"};
    char firstInitial{'J'};
    void print()const{
        std::cout << "Employee " << name << " has first initial" << firstInitial << "\n";
    }
};
int main (){
    Employee e{};
    e.print();
    e.name="Mark";
    e.print();
    return 0;
}
