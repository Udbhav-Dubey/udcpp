#include <iostream>
#include <string>
template<typename T> // typename is simply a keyword telling compiler T is placeholder
T get_greater(T a,T b){
    if (a>b){
        return a;
    }
    else {return b;}
}
Struct Book{
    std::string title;
    int pages;
};
int main() {
    std::cout << "Greater in 5 and 10 is : " << get_greater(5,10) << std::endl;
    std::cout << "Greater of 'Apple' and 'Orange' is " << get_greater(std::string("Apple"),std::string("Orange")) << std::endl;
//Book bookA={"Moby Dick",400}; this will not work 
//Book bookB={"Dune",500};
return 0;
}

