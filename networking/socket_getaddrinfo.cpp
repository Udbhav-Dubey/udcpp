#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
int main (int argc,char *argv[]){
    if (argc!=2){
        std::cerr<< "Usage : " << argv[0] <<"hostname\n";
        return 1;
    }
    const char *hostname=argv[1];
    struct addrinfo hints{},*res,*p;
    int status;
    char ipstr[INET6_ADDRSTRLEN];
    memset(&hints,0,sizeof hints);
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_flags=AI_CANONNAME;

    if ((status=getaddrinfo(hostname,"http",&hints,&res))!=0){
        std::cerr<<"getaddrinfo : "<<gai_strerror(status)<<"\n";
        return 2;
    }
    std::cout << "Results for " << hostname << ":\n\n";

    for (p=res;p!=nullptr;p=p->ai_next){
        void*addr;
        std::string ipver;
        if (p->ai_family==AF_INET){
            struct sockaddr_in *ipv4=reinterpret_cast<struct sockaddr_in*>(p->ai_addr);
            addr=&(ipv4->sin_addr);
            ipver="IPv4";
        }
        else {
            struct sockaddr_in6 *ipv6=reinterpret_cast<struct sockaddr_in6*>(p->ai_addr);
            addr=&(ipv6->sin6_addr);
            ipver="IPv6";
        }
        inet_ntop(p->ai_family,addr,ipstr,sizeof ipstr);
        std::cout << " " << ipver << ":" << ipstr;

        int sockfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol);
        if (sockfd==-1){
            perror(" socket ");
            std::cout << " ....Failed\n";
        }
        else {
            std::cout << "...socket created successfully(fd= " <<sockfd << ")\n";
            close(sockfd);
        }
    }
freeaddrinfo(res);
return 0;
}
