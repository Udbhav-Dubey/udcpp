#include <iostream>
namespace Foo{
    void printHi(){std::cout << "Hi!\n";}
};
int main (){
    Foo::printHi();
    return 0;
}
