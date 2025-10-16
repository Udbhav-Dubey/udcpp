#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string>
#include <cstring>
#include <unistd.h>
#define MAXDATASIZE 100

void *get_in_addr(struct sockaddr*sa){
    if (sa->sa_family==AF_INET){
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}
int main (int argc,char*argv[]){
    if (argc!=3){
        std::cerr<<"error in main only \n";
        return 1;
    }
    struct addrinfo hints{},*servinfo,*p;
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_STREAM;

    int rv;
    if ((rv=getaddrinfo(argv[1],argv[2],&hints,&servinfo))!=0){
        std::cerr<<"error in get addrinfo " << gai_strerror(rv) << "\n";
        return 1;
    }
    int sockfd;
    char s[INET6_ADDRSTRLEN];
    for (p=servinfo;p!=nullptr;p=p->ai_next){
        if ((sockfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol))==-1){
            perror("error in socket ");
            continue;
        }
        if (connect(sockfd,p->ai_addr,p->ai_addrlen)==-1){
            perror("error in connect");
            close(sockfd);
            continue;
        }
        break;
    }
    if (p==nullptr){
        std::cerr<<"error in connecting \n";
        return 2;
    }
    inet_ntop(p->ai_family,get_in_addr((struct sockaddr*)p->ai_addr),s,sizeof s);
    std::cout << "client : connected to " << s << "\n";
    freeaddrinfo(servinfo);
    std::string message="how you doin joe???\n";
    if (send(sockfd,message.c_str(),message.size(),0)==-1){
        perror("send");
    }
    char buf[MAXDATASIZE];
    int recv_bytes=recv(sockfd,buf,MAXDATASIZE-1,0);
    if (recv_bytes==-1){
        perror("recv");
        close (sockfd);
        return 1;
    }
    buf[recv_bytes]='\0';
    std::cout << "client : recieved " << buf << "\n";
    close (sockfd);
    return 0;
}
