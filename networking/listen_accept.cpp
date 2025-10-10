#include <iostream>
#include <cstring>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#define BACKLOG 10
int main (){
    struct addrinfo hints{},*res,*p;
    memset(&hints,0,sizeof(hints));
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_flags=AI_PASSIVE;
    int yes=1;
    int status=getaddrinfo(NULL,"3030",&hints,&res);
    if (status!=0){
        std::cerr<<"error in getaddrinfo" <<gai_strerror(status) <<"\n";
        return 1;
    }
    int sockfd;
    for (p=res;p!=nullptr;p=p->ai_next){
    sockfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol);
    if (sockfd==-1){
        perror("error in sockfd");
        continue;
    }
    // RESUSE PART
        if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int))==-1){
            perror("setsockopt");
            close(sockfd);
            freeaddrinfo(res);
            return 2;
        } 
        if (bind(sockfd,p->ai_addr,p->ai_addrlen)==-1){
            perror("bind");
            close(sockfd);
            continue;
        }
        break;
    }
    if(p==nullptr){
        std::cerr <<"failed to bind to any address\n";
        freeaddrinfo(res);
        return 3;
    }
    freeaddrinfo(res);
    std::cout << "[+] bound successfully on port " << "3030" << "\n";

    if (listen(sockfd,BACKLOG)==-1){
        perror("listen");
        close(sockfd);
        return 4;
    }
    std::cout << "[+] listening for incoming connections \n";
    
    struct sockaddr_storage their_addr;
    socklen_t addr_size=sizeof their_addr;
    int new_sd=accept(sockfd,(struct sockaddr*)&their_addr,&addr_size);
    if (new_sd==-1){
        perror("accept");
        close(sockfd);
        return 5;
    }
    char ipstr[INET6_ADDRSTRLEN];
    void *addr;
    if (their_addr.ss_family==AF_INET){
        struct sockaddr_in* ipv4=(struct sockaddr_in*)&their_addr;
        addr=&(ipv4->sin_addr);
    }else {
        struct sockaddr_in6* ipv6=(struct sockaddr_in6*)&their_addr;
        addr=&(ipv6->sin6_addr);
    }
    inet_ntop(their_addr.ss_family,addr,ipstr,sizeof ipstr);
    std::cout << "[+] connection from " << ipstr << "\n";

    const char*msg="kese hai reh client to \n";
    send(new_sd,msg,strlen(msg),0);
    std::cout << "[+] message sent.closing connection\n";

    close(new_sd);
    close(sockfd);
    std::cout << "[+]server shut down.\n";
    return 0;
}
