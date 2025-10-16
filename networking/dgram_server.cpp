#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>

#define port "6969"
#define MAXBUFFLEN 100

void *get_in_addr(struct sockaddr *sa){
    if (sa->sa_family==AF_INET){
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}
int main (){
    int sockfd;
    struct addrinfo hints{},*res,*p;
    int rv;
    struct sockaddr_storage their_addr{};
    socklen_t addr_len;
    char buf[MAXBUFFLEN];
    char s[INET6_ADDRSTRLEN];

    memset(&hints,0,sizeof(hints));
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_DGRAM;
    hints.ai_flags=AI_PASSIVE;

    if ((rv=getaddrinfo(nullptr,port,&hints,&res))!=0){
        std::cerr<<"error in getaddrinfo" << gai_strerror(rv)<<"\n";
        return 1;
    }
    for (p=res;p!=nullptr;p=p->ai_next){
        sockfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol);
        if (sockfd==-1){
            perror("socket");
            continue;
        }
        if (bind(sockfd,p->ai_addr,p->ai_addrlen)==-1){
            close(sockfd);
            perror("bind");
            continue;
        }
        break;
    }
    if (p==nullptr){
        std::cerr<<"failed to bind successfully";
        return 2;
    }
    freeaddrinfo(res);
    std::cout << "now waiting for client : ";   
    addr_len=sizeof their_addr;
    int numbytes=recvfrom(sockfd,buf,MAXBUFFLEN-1,0,(struct sockaddr*)&their_addr,&addr_len);
    if (numbytes==-1){
        perror("recv from");
        exit(1);
    }
    buf[numbytes]='\0';
    inet_ntop(their_addr.ss_family,get_in_addr((struct sockaddr*)&their_addr),s,sizeof(s));
    std::cout << "listener : got packets from "<< s << "\n";
    std::cout << "listener : packet is "<< numbytes << "bytes long \n";
    std::cout << "listener : packet containts " << buf << "\n";
    close (sockfd);
    return 0;
}
