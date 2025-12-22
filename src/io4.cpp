#include <iostream>
#include <string>
#include <sstream>
int main (){
    std::string s ="10 20 30 abc 40 50";
    std::stringstream ss;
    ss<<s;
    int x;
    while(true){
        if (ss>>x){
            std::cout << " ";
        }
        else {
            if (ss.eof()){
                break;
            }
            ss.clear();
            std::string junk;
            ss>>junk;
        }
    }
    return 0;
}
