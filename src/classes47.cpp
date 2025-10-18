#include <iostream>
class Foo{
    public:
        Foo(){
            std::cout << "Foo default constructed\n";
        }
};
int main (){
    Foo foo{}; 
    return 0;
}
