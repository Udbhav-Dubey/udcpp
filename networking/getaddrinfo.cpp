#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <memory>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
int main (int argc,char*argv[]){
    if (argc!=2){
        std::cerr<<"usage: " << argv[0] << "hostname\n";
        return 1;
    }
    const char *hostname=argv[1];

    struct addrinfo hints{};
    struct addrinfo *res=nullptr;
    memset(&hints,0,sizeof hints);
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_flags=0;

    int status=getaddrinfo(hostname,nullptr,&hints,&res);
    if (status!=0){
        std::cerr<<"getaddrinfo error: " << gai_strerror(status) << "\n";
        return 2;
    }
    std::unique_ptr<addrinfo,decltype(&freeaddrinfo)>res_guard(res,freeaddrinfo);
    std::cout << "IP address for " << hostname << ":\n\n";

    for (struct addrinfo *p=res;p!=nullptr;p=p->ai_next){
        void *addr;
        std::string ipver;
        if (p->ai_family==AF_INET){
            sockaddr_in *ipv4=reinterpret_cast<sockaddr_in*>(p->ai_addr);
            addr=&(ipv4->sin_addr);
            ipver="IPV4";
        }
        else if (p->ai_family==AF_INET6){
            sockaddr_in6 *ipv6=reinterpret_cast<sockaddr_in6*>(p->ai_addr);
            addr=&(ipv6->sin6_addr);
            ipver="IPv6";
       }
        else {
            continue;
        }
        char ipstr[INET6_ADDRSTRLEN];
        inet_ntop(p->ai_family,addr,ipstr,sizeof ipstr);
        std::cout << " " << ipver << ": " << ipstr << "\n";
    }
    //freeaddrinfo(res);
    return 0;
}
