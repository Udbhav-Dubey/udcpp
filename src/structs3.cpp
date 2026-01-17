#include <iostream>
struct Foo{
    int a{};
    int b{};
    int c{};
};
int main (){
    Foo f1{.a{1},.c{3}};
    Foo f2{.a=1,.c=3};
    Foo f3{.b{2},.a{1}};
    return 0;
}
