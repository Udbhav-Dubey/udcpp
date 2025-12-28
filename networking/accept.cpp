#include <iostream>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
constexpr const char * PORT="9090";
constexpr int BACKLOG= 10;
int main (){
    addrinfo hints{},*res;
    std::memset(&hints,0,sizeof(hints));
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_flags=AI_PASSIVE;
    if (getaddrinfo(nullptr,PORT,&hints,&res)!=0){
        perror("getaddrinfo");
        return 1;
    }
    int listen_fd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
    if (listen_fd<0){
        perror("socket");
        return 1;
    }
    int yes=1;
    setsockopt(listen_fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(yes));
    if (bind(listen_fd,res->ai_addr,res->ai_addrlen)<0){
        perror("bind");
        close(listen_fd);
        return 1;
    }
    freeaddrinfo(res);
    if (listen(listen_fd,BACKLOG)<0){
        perror("listen");
        close(listen_fd);
        return 1;
    }
    std::cout << "Server listing on port : " << PORT << "\n";
    sockaddr_storage client_addr;
    socklen_t addr_size=sizeof(client_addr);
    int client_fd=accept(listen_fd,(sockaddr*)&client_addr,&addr_size);
    if (client_fd<0){
        perror("accept");
        close(listen_fd);
        return 1;
    }
    sockaddr_storage peer_addr;
    socklen_t peer_len=sizeof(peer_addr);
    if (getpeername(client_fd,(sockaddr*)&peer_addr,&peer_len)==-1){
        perror("getpeername");
    }
    else {
        char ipstr[INET6_ADDRSTRLEN];
        char port;
        if (peer_addr.ss_family==AF_INET){
            auto *s=(sockaddr_in*)&peer_addr;
            port=ntohs(s->sin_port);
            inet_ntop(AF_INET,&s->sin_addr,ipstr,sizeof (ipstr));
        }
        else {
            auto *s=(sockaddr_in*)&peer_addr;
            port=ntohs(s->sin_port);
            inet_ntop(AF_INET6,&s->sin6_addr,ipstr,sizeof ipstr);
        }
        std::cout << "peer connected from : " << ipstr << " : " << port << "\n"; 
    }
    std::cout << "Client connection\n";
    const char*msg="Hello from server\n";
    send(client_fd,msg,std::strlen(msg),0);
    close(client_fd);
    close(listen_fd);
    return 0;
}
