#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
int main (){
    const char*hostname="google.com";
    struct addrinfo hints{},*res;
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype=SOCK_STREAM;
    int status=getaddrinfo(hostname,nullptr,&hints,&res);
    if (status!=0){
        std::cerr<<"getaddrinfo error." << gai_strerror(status) << std::endl;
        return 1; 
    }
    char ipstr[INET6_ADDRSTRLEN];
    for (auto p=res;p!=nullptr;p=p->ai_next){
        void* addr;
        const char * ipver;
        if (p->ai_family==AF_INET){
            struct sockaddr_in*ipv4=(struct sockaddr_in*)p->ai_addr;
            addr=&(ipv4->sin_addr);
            ipver="IPv4";
        }
        else {
            struct sockaddr_in6*ipv6=(struct sockaddr_in6*)p->ai_addr;
            addr=&(ipv6->sin6_addr);
            ipver="IPv6";
        }
        inet_ntop(p->ai_family,addr,ipstr,sizeof ipstr);
        std::cout << ipver << ":" << ipstr << std::endl;
    }
    freeaddrinfo(res);
    return 0;
}
