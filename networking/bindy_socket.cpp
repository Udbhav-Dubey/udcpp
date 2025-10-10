#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstdlib>

int main (){
    struct addrinfo hints{},*res;
    int sockfd;
    int status;
    int yes=1;

    memset(&hints,0,sizeof hints);
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_flags=AI_PASSIVE;

    status=getaddrinfo(NULL,"3490",&hints,&res);
    if (status!=0){
        std::cerr<<"getaddrinfo error : " << gai_strerror(status) << std::endl;
        return 1;
    }
    
    sockfd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
    if (sockfd==-1){
        perror("socket");
        freeaddrinfo(res);
        return 2;
    }
    if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof yes)==-1){
        perror("setsockpt");
        close(sockfd);
        freeaddrinfo(res);
        return 3;
    }
    if (bind(sockfd,res->ai_addr,res->ai_addrlen)==-1){
        perror("bind");
        close(sockfd);
        freeaddrinfo(res);
        return 4;
    }
    char ipstr[INET6_ADDRSTRLEN];
    void *addr;
    const char *ipver;
    if (res->ai_family==AF_INET){
        struct sockaddr_in *ipv4=(struct sockaddr_in*)res->ai_addr;
        addr=&(ipv4->sin_addr);
        ipver="IPv4";
    }else{
        struct sockaddr_in6 *ipv6=(struct sockaddr_in6 *)res->ai_addr;
        addr=&(ipv6->sin6_addr);
        ipver="IPv6";
    }
    inet_ntop(res->ai_family,addr,ipstr,sizeof ipstr);
    std::cout << "bound successfully to " << ipver << "address " << ipstr << " on port 3490 " << std::endl;

    freeaddrinfo(res);
    close(sockfd);
    return 0;
}
