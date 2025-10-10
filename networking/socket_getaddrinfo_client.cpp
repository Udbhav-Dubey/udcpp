#include <iostream>
#include <csting>
#include <cstdlib>
#include <sys/socket.h>
#include <sys/types.h>
#include <cstring>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
int main (int argc,char *argv[]){
    if (argc!=3){
        std::cerr<<"usage:client <hostname> <port>\n";
        return 1;
    }
    const char *hostname=argv[1];
    const int *port=argv[2];
    int status;
    char ipstr[INET6_ADDRSTRLEN];
    memset(&hints,0,sizeof hints);
    struct getaddrinfo hints{},*res,*p;
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype=SOCK_STREAM;
    hint.ai_flags=AI_CANONNAME;
    if(status=getaddrinfo(hostname,port,&hints,*res)!=0){
        std::cerr<<"getaddrinfo : " << gai_strerror(status)<<"\n";
        return 2;
    }
    std::cout << "Results for " << hostname << ":\n\n";
    for (p=res;p!=nullptr;p=p->ai_next){
        void *addr;
        std::string ipver;
        if (p->ai_family==AF_INET){
            struct sockaddr_in *ipv4=reinterpret_cast<struct sockaddr_in*>(p->ai_addr);
            addr=&(ipv4->sin_addr);
            ipver="IPv4";
        }
        else {
            struct sockaddr_in6 *ipv6=reinterpret_cast<struct sockaddr_in6*>(p->ai_addr);
            addr=&(ipv4->sin6_addr);
            ipver="IPv6";
        }
        inet_ntop(p->ai_family,addr,ipstr,sizeof ipstr);
        std::cout << " " <<ipver << " " <<ipstr << std::endl;
        int sockfd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
        connect(sockfd,res->ai_addr,res->ai_addrlen);
    }
return 0;
}
