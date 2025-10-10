#include <iostream>
#include <netdb.h>
#include <cstring>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

int main (int argc,char *argv[3]){
    if (argc!=3){
        std::cerr<<"usage: "<<argv[0] <<"<hostname><port>\n";
        return 1;
    }
    const char* hostname=argv[1];
    const char*port=argv[2];
    struct addrinfo hints{},*res,*p;
    memset(&hints,0,sizeof hints);
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype=SOCK_STREAM;
    
    int status=getaddrinfo(hostname,port,&hints,&res);
    if (status!=0){
        std::cerr<<"problem in status " << gai_strerror(status) <<"\n";
        return 2;
    }
    int sockfd;
    for(p=res;p!=nullptr;p=p->ai_next){
        sockfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol);
        if (sockfd==-1){
            perror("socket error");
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
        std::cerr<<"failed to connect \n";
        freeaddrinfo(res);
        return 3;
    }
    std::cout << "connected to " << hostname <<"on port " << port << "\n";
    const char *msg="server main client bol raha hun.\n";
    send(sockfd,msg,strlen(msg),0);

    char buffer[1024];
    int bytes_recieved=recv(sockfd,buffer,sizeof(buffer)-1,0);
    if (bytes_recieved>0){
        buffer[bytes_recieved]='\0';
        std::cout << "server says : " << buffer;
    }
    close(sockfd);
    freeaddrinfo(res);
    return 0;
}
