#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
int main (){
    int sockfd=socket(AF_INET,SOCK_DGRAM,0);
    if (sockfd<0){perror("socket faild !");}
    sockaddr_in server_addr{};
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(3030);
    server_addr.sin_addr.s_addr=INADDR_ANY;
    if (bind(sockfd,(sockaddr*)&server_addr,sizeof(server_addr))<0){
        perror("bind");return 1;
    }
    std::vector<char> buffer(1024);
    sockaddr_storage client_addr{};
    socklen_t client_len=sizeof(client_addr);
    int bytes_recieved=recvfrom(sockfd,buffer.data(),buffer.size(),0,(sockaddr*)&client_addr,&client_len);
    if (bytes_recieved>0){
        std::string msg(buffer.begin(),buffer.begin()+bytes_recieved);
        std::cout <<"Client says : " << msg << "\n";
        std::string reply="hello from udp server ";
        sendto(sockfd,reply.c_str(),reply.size(),0,(sockaddr*)&client_addr,client_len);
    }
    close(sockfd);
    return 0;
}
