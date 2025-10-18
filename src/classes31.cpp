#include <iostream>
#include <string_view>
int main (){
    std::string_view sv{"hello,world!"};
    std::cout << sv.length();
    return 0;
}
