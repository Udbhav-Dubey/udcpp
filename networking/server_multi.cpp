#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstring>
#include <string>
#include <sys/wait.h>
#include <unistd.h>
#include <cerrno>
#include <csignal>
#define port "3030"
#define backlog 10
void sigchld_handler(int){
    int saved_errno=errno;
    while(waitpid(-1,nullptr,WNOHANG)>0);
    errno=saved_errno;
}
void *get_in_addr(struct sockaddr *sa){
    if (sa->sa_family=AF_INET){
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}
int main (){
    int sockfd,newfd;
    int yes=1;
    struct addrinfo hints{},*servinfo,*p;
    struct sockaddr_storage their_addr{};
    socklen_t sin_size;
    struct sigaction sa{};
    char s[INET6_ADDRSTRLEN];
    int rv;

    memset(&hints,0,sizeof(hints));
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_flags=AI_PASSIVE;

    if ((rv=getaddrinfo(nullptr,port,&hints,&servinfo))!=0){
        std::cerr<<"getaddrinfo: " <<gai_strerror(rv)<<"\n";
        return 1;
    }
    for (p=servinfo;p!=nullptr;p=p->ai_next){
        sockfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol);
        if (sockfd==-1){
            perror("error in sockets");
            continue;
        }
        if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int))==-1){
            perror("error in setsockopt");
            exit(1);
        }  
        if (bind(sockfd,p->ai_addr,p->ai_addrlen)==-1){
            close(sockfd);
            perror("problem in bind");
            continue;
        }
        break;
    }
    freeaddrinfo(servinfo);
    if (p==nullptr){
        std::cerr<<"no socket was binded ";
        exit(1);
    }
    if (listen(sockfd,backlog)==-1){
        perror("cannot listen ");
        exit(1);
    }
    sa.sa_handler=sigchld_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags=SA_RESTART;
    if (sigaction(SIGCHLD,&sa,nullptr)==-1){
        perror("sigaction failed");
        exit(1);
    }
    std::cout << "server waiting for connection : \n";
    while(true){
        sin_size=sizeof their_addr;
        newfd=accept(sockfd,(struct sockaddr*)&their_addr,&sin_size);
        if (newfd==-1){
            perror("accept has problems ");
            continue;
        }
        inet_ntop(their_addr.ss_family,get_in_addr((struct sockaddr*)&their_addr),s,sizeof(s));
        std::cout <<"server : got connection from " << s << "\n";
        if (!fork()){
            close(sockfd);
            const char*msg="hello world!\n";
            if (send(newfd,msg,strlen(msg),0)==-1){
                perror("send");}
                close(newfd);
                exit(0);
            }
            close(newfd);
        }
    return 0;
}
