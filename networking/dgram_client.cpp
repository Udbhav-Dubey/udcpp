#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <cstring>
#include <unistd.h>
#define port "6969"

int main (int argc,char * argv[]){
    if (argc!=3){
        std::cerr<<"error in arguments only ";
        return 0;
    }
    int sockfd;
    struct addrinfo hints{},*res,*p;
    int rv;
    memset(&hints,0,sizeof(hints));
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_DGRAM;
    if ((rv=getaddrinfo(argv[1],port,&hints,&res))!=0){
        std::cerr<<"error in getting address info " <<gai_strerror(rv)<<"\n";
        return 1;
    }
    for (p=res;p!=nullptr;p=p->ai_next){
        sockfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol);
        if (sockfd==-1){
            perror("socket");
            continue;
        }
        break;
    }
    if (p==nullptr){
        std::cerr<<"failed to create socket\n";
        return 2;
    }
    int numbytes=sendto(sockfd,argv[2],strlen(argv[2]),0,p->ai_addr,p->ai_addrlen);
    if (numbytes==-1){
        perror("sendto");
        exit(1);
    }
    std::cout << "sent " << numbytes<<"bytes to  " << argv[1] << "\n";
    freeaddrinfo(res);
    close(sockfd);
    return 0;
}
