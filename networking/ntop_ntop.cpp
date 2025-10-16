#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
int main (){
    sockaddr_in addr{};
    addr.sin_family=AF_INET;
    inet_pton(AF_INET,"127.0.0.1",&addr.sin_addr);
    char ipstr[INET_ADDRSTRLEN];
    if (inet_ntop(AF_INET,&addr.sin_addr,ipstr,sizeof(ipstr))==nullptr){
        perror("inet_ntop failed ");
    }
    else {
        std::cout << "IP address : "<<ipstr<<"\n";
        }
    return 0;
}
