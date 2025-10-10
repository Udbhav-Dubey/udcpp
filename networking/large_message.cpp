#include <iostream>
#include <cstring>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#define PORT "8080"
#define BACKLOG 10
int main (){
    struct addrinfo hints{},*res;
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_flags=AI_PASSIVE; 
    getaddrinfo(NULL,PORT,&hints,&res);
    int sockfd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
    bind(sockfd,res->ai_addr,res->ai_addrlen);
    listen(sockfd,BACKLOG);
    std::cout <<"[server] Listening on port " << PORT << "\n";
    sockaddr_storage their_addr{};
    socklen_t=addr_size=sizeof(their_addr);
    int new_fd=accept(sockfd,(sockaddr*)&their_addr,&addr_size);
    std::cout << "Server connection accepted!\n";
    char buf[4096];
    int total=0;
    while(true){
        int bytes
    }
}
