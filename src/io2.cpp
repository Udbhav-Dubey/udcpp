#include <iostream>
#include <string>
#include <sstream>
int main (){
    std::string s="42 hello 3.14";
    std::stringstream ss;
    ss<<s;
    int a;
    double b;
    std::string c;
    ss>>a>>b>>c;
    std::cout << "int=" << a << " double=" << b << " string=" << c << "\n";
    std::cout << "fail= "<< ss.fail() << " eof= " << ss.eof();
    ss.clear();
    ss>>c;
    std::cout << "c= " << c << "\n";
    return 0;
}
