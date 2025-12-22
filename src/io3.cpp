#include <iostream>
#include <sstream>
#include <string>
int main (){
    std::string s;
    s="10 20 30 abc 40 50";
    std:: stringstream ss;
    ss<<s;
    int x;
    while(ss>>x){
        std::cout << x << " ";
    }

    return 0;
}
