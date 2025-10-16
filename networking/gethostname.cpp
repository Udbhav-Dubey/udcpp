#include <iostream>
#include <unistd.h>
#include <cstring>
int main (){
    char hostname[256];
    if (gethostname(hostname,sizeof(hostname))==0){
        std::cout << "Local host name : " <<hostname <<"\n";
    }
    else {
        perror("gethostname failed");
    }
    return 0;
}
