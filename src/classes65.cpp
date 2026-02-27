#include <iostream>
class Base{
   public:
        void print()const{
            std::cout << "from base\n";
        }
};
class Derived : public Base{
public:
    void print()const{
        std::cout << "Derived\n";
        Base::print();
    }
};
int main (){
    Derived der;
    der.print();
    return 0;
}
