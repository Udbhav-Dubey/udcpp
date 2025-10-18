#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <vector>
#include <unistd.h>

bool send_all(int sockfd,const std::string&data){
    size_t total_data=0;
    size_t len=data.size();
    while(total_data<len){
        ssize_t sent=send(sockfd,data.data()+total_data,len-total_data,0);
        if (sent<=0){
            return 0;
        }
        total_data+=sent;
    }
    return true;
}
int main (int argc,char *argv[]){
    if(argc<2){std::cerr<<"error in main only";return 1;}
    std::string hostname=argv[1];
    std::string port;
    if (argc>=3){
        port = argv[2];
    }
    else port = "80";
    struct addrinfo hints{},*res,*p;
    memset(&hints,0,sizeof(hints));
    hints.ai_family=AF_UNSPEC;
    hints.ai_socktype=SOCK_STREAM;
    if (getaddrinfo(hostname.c_str(),port.c_str(),&hints,&res)!=0){
        std::cerr<<"error in getaddrinfo";
        return 2;
    }
    int sockfd;
    for (p=res;p!=nullptr;p=p->ai_next){
        if ((sockfd=socket(p->ai_family,p->ai_socktype,p->ai_protocol))==-1){
                continue;
            }
        if (connect(sockfd,p->ai_addr,p->ai_addrlen)==0){
            break;
        }
        close(sockfd);
        sockfd=-1;
    }
    freeaddrinfo(res);
    if (p==nullptr){
        std::cerr<<"failed to connect to any address\n";
        return 3;
    }
    std::string request="GET / HTTP/1.1\r\n"
        "Host: "+ hostname +"\r\n"
        "Connection: close\r\n"
        "\r\n";
    if (!send_all(sockfd,request)){
        std::cerr<<"Failed to connect to send request \n";
        close (sockfd);
        return 1;
    }
    char buffer[4096];
    ssize_t n;
    while((n=recv(sockfd,buffer,sizeof(buffer),0))>0){
        std::cout.write(buffer,n);
    }
    if (n<0){
        perror("recv");
    }
    close(sockfd);
    return 0;
}
