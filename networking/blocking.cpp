include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
int main (){
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    fcntl(sockfd,F_SETFL,O_NONBLOCK);
    char buffer[1024];
    int n=recv(sockfd,buffer,sizeof(buffer)-1,0);
        if (n<0){
            if (errno==EAGAIN||errno==EWOULDBLOCK){
                std::cout << "No data available right now\n";
            }
            else {perror("recv");}
        }
    return 0;
}
