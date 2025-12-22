#include <iostream>
#include <sstream>
#include <string>

int main (){
    std::string s="42 3.14 hello";
    //std::stringstream ss << s;
    std::stringstream ss(s);
    int a;
    double b;
    std::string sa;
    ss>>a>>b>>sa;
    std::cout << "int=" << a << " double=" << b << " string=" << sa << "\n";
    return 0;
}
