#include <iostream>
#include <poll.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

constexpr const char* PORT ="9034";
int get_listener_socket(){
    struct addrinfo hints{};
    struct addrinfo* res;
    int listener;
    std::memset(&hints,0,sizeof(hints));
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_flags=AI_PASSIVE;
    int rv=getaddrinfo(nullptr,PORT,&hints,&res);
    if (rv!=0){
        std::cerr<<"getaddrinfo: " << gai_strerror(rv) <<"\n";
        return -1;
    }
    listener=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
    if (listener==-1){
        perror("socket");
        freeaddrinfo(res);
        return -1;
    }
    int yes=1;
    setsockopt(listener,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(yes));
    if (bind(listener,res->ai_addr,res->ai_addrlen)==-1){
        perror("bind");
        close(listener);
        freeaddrinfo(res);
        return -1;
    }
    freeaddrinfo(res);
    if (listen(listener,10)==-1){
        perror("listen");
        close(listener);
        return -1;
    }
    return listener;
}
void accept_new_connection(int listener,struct pollfd pfds[],int& fd_count){
    struct sockaddr_storage remoteaddr;
    socklen_t addrlen=sizeof remoteaddr;
    int newfd=accept(listener,(struct sockaddr*)&remoteaddr,&addrlen);
    if (newfd==-1){
        perror("accept");
        return ;
    }
    pfds[fd_count].fd=newfd;
    pfds[fd_count].events=POLLIN;
    pfds[fd_count].revents=0;
    std::cout << "New client connected on fd " << newfd << "\n";
    fd_count++;
}
void handle_client_data(int listener,struct pollfd pfds[],int &fd_count,int i){
    char buf[256];
    int sender_fd=pfds[i].fd;
    int nbytes=recv(pfds[i].fd,buf,sizeof(buf),0);
    if (nbytes<=0){
        if (nbytes==0){std::cout << "Client fd : " << pfds[i].fd << " disconnected\n";}
    else {
        perror("recv");
    }
    close (pfds[i].fd);
    pfds[i]=pfds[fd_count-1];
    fd_count--;
    i--;
    }
    else{
        //std::cout << "Recieved from fd : " << pfds[i].fd << " : " << std::string(buf,nbytes);
        for (int j=0;j<fd_count;j++){
            int dest_fd=pfds[j].fd;
            if (dest_fd!=listener && dest_fd!=sender_fd){
                if (send(dest_fd,buf,nbytes,0)==-1){
                    perror("send");
                }
            }
        }
    }
}
int main (){
    struct pollfd pfds[2];
    int fd_count=2;
    pfds[0].fd=STDIN_FILENO;
    pfds[0].events=POLLIN;
    pfds[0].revents=0;
    //std::cout << "poll is running\n ";
    int listener=get_listener_socket();
    if (listener==-1){
        std::cerr<<"Failed to create listener\n";
        return 1;
    }
    pfds[1].fd=listener;
    pfds[1].events=POLLIN;
    pfds[1].revents=0;
    std::cout << "listing on port : " << PORT << "\n";
    while(true){
        int ready=poll(pfds,fd_count,-1);
        if(ready==-1){
            perror("poll");
            std::exit(1);
        }
        for (int i=0;i<fd_count;i++){
            if (pfds[i].revents&POLLIN){
                if (pfds[i].fd==STDIN_FILENO){
                    std::cout << "STDin readable\n";
                }
            
            else if (pfds[i].fd==listener){
                //std::cout << "Incoming Connection detected (listener readable)\n";
                accept_new_connection(listener,pfds,fd_count);
            }
                else {//std::cout << "CLient fd " << pfds[i].fd << "is reachable\n";
                      handle_client_data(listener,pfds,fd_count,i);}
            }
        }
    }
    return 0;
}
