#include <iostream>
#include <string>
#include <unistd.h>
#include <cerrno>
int main (){
    char hostname[256];
    if (gethostname(hostname,sizeof(hostname))==-1){
        std::cerr<<"error in getting hostname :" <<"\n";
        return 1;
    }
    std::cout << "local hostname :" << hostname << "\n";
    return 0;
}
