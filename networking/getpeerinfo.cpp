#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
int main (){
    int server_fd=socket(AF_INET,SOCK_STREAM,0);
    sockaddr_in addr{};
    addr.sin_family=AF_INET;
    addr.sin_port=htons(3300);
    addr.sin_addr.s_addr=INADDR_ANY;
    bind(server_fd,(sockaddr*)&addr,sizeof(addr));
    listen(server_fd,1);
    int client_fd=accept(server_fd,nullptr,nullptr);
    sockaddr_in peer_addr{};
    socklen_t peer_len=sizeof(peer_addr);
    if (getpeername(client_fd,(sockaddr*)&peer_addr,&peer_len)==0){
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET,&peer_addr.sin_addr,ip,sizeof(ip));
        std::cout << "client connected to ip ::" << ip << "port : "<< ntohs(peer_addr.sin_port)<<"\n";
    }
    close(server_fd);
    close(client_fd);
    return 0;
}
