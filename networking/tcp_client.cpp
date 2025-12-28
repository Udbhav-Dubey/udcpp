#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <cstring>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
int main (){
    const char*hostname="www.example.com";
    const char* service="80";
    struct addrinfo hints;
    struct addrinfo *servinfo=nullptr;
    struct addrinfo *p=nullptr;
    int sockfd=-1;
    int rv;
    std::memset(&hints,0,sizeof(hints));
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype=SOCK_STREAM;
    rv=getaddrinfo(hostname,service,&hints,&servinfo);
    if (rv!=0){
        std::cerr<<"getaddrinfo : "<< gai_strerror(rv) << "\n";
        return 1;
    }
    for (p=servinfo;p!=nullptr;p->ai_next){
        sockfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol);
        if (sockfd==-1){
            perror("socket");
            return 1;
        }
        if (connect(sockfd,p->ai_addr,p->ai_addrlen)==-1){
            perror("connect");
            close(sockfd);
            sockfd=-1;
            continue;
        }
        break;
    }
    if (p==nullptr){
        std::cerr<<"Failed to connect to my address\n";
        freeaddrinfo(servinfo);
        return 2;
    }
    std::cout << "connected succesfully\n";
    freeaddrinfo(servinfo);
    close(sockfd);
    std::cout <<"socket closed successfully\n";
    return 0;
}
