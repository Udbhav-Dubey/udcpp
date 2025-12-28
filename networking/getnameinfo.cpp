#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <string>
int main (){
    int sockfd;
    struct addrinfo hints,*res;
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_flags=AI_PASSIVE;
    if (getaddrinfo(nullptr,"3490",&hints,&res)!=0){
        perror("getaddrinfo");
        return 1;
    }
    sockfd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
    bind(sockfd,res->ai_addr,res->ai_addrlen);
    listen(sockfd,10);
    std::cout << "waiting for connections\n";
    struct sockaddr_storage client_addr;
    socklen_t addrlen=sizeof(client_addr);
    int client_fd=accept(sockfd,(struct sockaddr*)&client_addr,&addrlen);
    char host[NI_MAXHOST];
    char service[NI_MAXSERV];
    int rv=getnameinfo(
    (struct sockaddr*)&client_addr,
    addrlen,
    host,sizeof(host),service,sizeof(service),0
            );
    if (rv!=0){
        std::cerr<<"getnameinfo: "<< gai_strerror(rv)<<"\n";
    }
    else {
        std::cout << "Client connected from host : "<< host << "service =" << service <<"\n";
    }
    close(client_fd);
    close(sockfd);
    freeaddrinfo(res);
}
