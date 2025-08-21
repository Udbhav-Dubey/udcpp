#include <iostream>
struct Foo{
    void printHi(){std::cout << "Hi!\n";}
};
int main (){
    Foo f{};
    f.printHi();
return 0;
}
