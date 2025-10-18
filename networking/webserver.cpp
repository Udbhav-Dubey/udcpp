#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

bool send_all(int sockfd,const std::string &data){
    size_t total=0;
    size_t len=data.size();
    while(total<len){
        ssize_t sent=send(sockfd,data.data()+total,len-total,0);
        if (sent<=0){return false;}
        total+=sent;
    }
    return true;
}
int main (int argc,char*argv[]){
    int port = 28333;
    if (argc>2){
        port = std::stoi(argv[1]);
    }
    int sockfd;
    sockaddr_in addr{};
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=INADDR_ANY;
    addr.sin_port=htons(port);
    
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if (sockfd<0){perror("socket");return 1;}
    int opt=1;
    setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    
    if (bind(sockfd,(struct sockaddr*)&addr,sizeof(addr))<0){
        perror("bind");
        return 2;
    }
    if (listen(sockfd,SOMAXCONN)<0){
        perror("listen");
        return 3;
    }
    std::cout <<"now the listing on port " << port << "\n";
    while(true){
        sockaddr_in client_addr{};
        socklen_t client_len=sizeof(client_addr);
        int client_sock=accept(sockfd,(struct sockaddr*)&client_addr,&client_len);
        if (client_sock<0){
            perror("accept");
            continue;
        }
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET,&client_addr.sin_addr,client_ip,sizeof(client_ip));
        int client_port = ntohs(client_addr.sin_port);
        std::cout << "connection from " << client_ip<<" : " << client_port << "\n";

        std::string request;
        char buffer[4096];
        while(true){
            ssize_t n=recv(client_sock,buffer,sizeof(buffer),0);
            if (n<=0) break;
            request.append(buffer,n);
            if (request.find("\r\n\r\n")!=std::string::npos) break;
        }
        size_t pos=request.find("\r\n");
        if (pos!=std::string::npos){
            std::cout << "Request : "<<request.substr(0,pos)<<"\n";
        }
        std::string response=
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length : 6\r\n"
            "Connection: close\r\n"
            "\r\n"
            "Hello Hello!\n";
        send_all(client_sock,response);
        close(client_sock);
    }
        return 0;
}
