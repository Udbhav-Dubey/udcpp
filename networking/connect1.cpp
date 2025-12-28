#include <iostream>
#include <netdb.h>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
constexpr const char* PORT="9090";
constexpr const char* HOST="127.0.0.1";
int main(){
    addrinfo hints,*res;
    std::memset(&hints,0,sizeof(hints));
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_STREAM;
    int rv=getaddrinfo(HOST,PORT,&hints,&res);
    if (rv!=0){
        perror("getaddrinfo");
        return 1;
    }
    int sockfd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
    if (sockfd<0){
        perror("socket");
        freeaddrinfo(res);
        return 1;
    }
    if (connect(sockfd,res->ai_addr,res->ai_addrlen)<0){
        perror("connect");
        close(sockfd);
        freeaddrinfo(res);
        return 1;
    }
    freeaddrinfo(res);
    std::cout << "connected to server "; 
    const char* msg="Hello from client\n";
    send(sockfd,msg,std::strlen(msg),0);
    char buf[1024];
    ssize_t n=recv(sockfd,buf,sizeof(buf-1),0);
    if (n>0){
        buf[n]='\0';
        std::cout << "Recieved: " << buf ;
    }
    close(sockfd);
    return 0;
}
