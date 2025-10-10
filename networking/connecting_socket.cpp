#include <iostream>
#include <cstring>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
int main (int argc,char *argv[]){
    if (argc!=3){
        std::cerr<<"Usage: " << argv[0]<<"hostname><port>\n";
        return 1;
    }
    const char*hostname=argv[1];
    const char*port=argv[2];
    struct addrinfo hints{},*res,*p;
    memset(&hints,0,sizeof hints);
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype=SOCK_STREAM;

    int sockfd;

    int status=getaddrinfo(hostname,port,&hints,&res);
    if (status!=0){
        std::cerr<<"getaddrinfo error : " <<gai_strerror(status)<<"\n";
        return 2;
    }
    for (p=res;p!=nullptr;p=p->ai_next){
        sockfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol);
        if (sockfd==-1){
            perror("socket");
            continue;
        }
        if (connect(sockfd,p->ai_addr,p->ai_addrlen)==-1){
            perror("connect");
            close(sockfd);
            continue;
        }
        break;
    }
    if (p==nullptr){
        std::cerr<<"Failed to connect\n";
        freeaddrinfo(res);
        return 3;
    }
    std::cout << "connected to " << hostname << "on port " << port << "\n";
    const char *msg="Hello server\n";
    send(sockfd,msg,strlen(msg),0);
    close(sockfd);
    freeaddrinfo(res);
    return 0;
}
