// sendto
int sendto(int sockfd,const void*msg,int len,unsigned int flags,const struct sockaddr *to,socklen_t tolen);

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <cstring>
#include <netinet.h>

int sockfd=socket(AF_INET,SOCK_DGRAM,0);
sockaddr_in dest_addr{};
dest_addr.sin_family=AF_INET;
dest_addr.sin_port=htons(12345);
inet_ptons(AF_INET,"127.0.0.1",&dest_addr.sin_addr);
std::string msg="Hello UDP!";
int byte_send=sendto(sockfd,msg.c_str(),msg.size(),0,struct (sockaddr*)&dest_addr,sizeof(dest_addr));
if (byte_send==-1){perror("send to failed");}


//recvfro,
int recvfrom(int sockfd,void*buf,int len,unsigned int flags,struct sockaddr* from,socklen_t fromlen);

#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <vector>

std::vector<char> buffer[1024];
sockaddr_storage sender_addr{};
socklen_t sender_len=sizeof(sender_addr);
int bytes_recieved=recvfrom(sockfd,buffer.data(),buffer.size(),0,(struct sockaddr*)&sender_addr,&sender_len);
if (bytes_recieved>0){
    std::string recieved_msg(buffer.begin(),buffer.begin()+bytes_recieved);
    std::cout << "Received : "  << recieved_msg << "\n";
}
