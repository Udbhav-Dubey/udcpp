#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>

int main (){
    struct addrinfo hints,*res;
    int sockfd;
    memset(&hints,0,sizeof hints);
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype=SOCK_STREAM;

    int status=getaddrinfo("www.example.com","80",&hints,&res);
    if (status!=0){
        std::cerr<<"getaddrinfo error: " <<gai_strerror(status) << std::endl;
        return 1;
    }
    sockfd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
    if (sockfd==-1){
        perror("socket");
        freeaddrinfo(res);
        return 2;
    }
    if (connect(sockfd,res->ai_addr,res->ai_addrlen)==-1){
        perror("connect");
        freeaddrinfo(res);
        return 3;
    }
    std::cout << "[+] Connected Successfully to www.example.com:80 " <<std::endl;
    freeaddrinfo(res);
    close(sockfd);
    return 0;
}
