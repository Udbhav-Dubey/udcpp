#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
int main (){
    struct addrinfo hints{},*res;
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype=SOCK_STREAM;
    int status=getaddrinfo("google.com","http",&hints,&res);
    if (status!=0){
        std::cerr<< "get addrinfo error : " <<gai_strerror(status)<<"\n";
        return 1;
    }
    int sockfd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
    if (sockfd==-1){
        perror("socket");
        freeaddrinfo(res);
        return 1;
    }
    std::cout << "[+] socket created successfully!\n";
    freeaddrinfo(res);
    close(sockfd);
    return 0;
}
