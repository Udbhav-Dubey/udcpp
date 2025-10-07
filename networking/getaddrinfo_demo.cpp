#include <iostream>
#include <cstring> // memset
#include <arpa/inet.h> // inet_pton,htons,ntohs
#include <sys/socket.h> // socket,bind
#include <netinet/in.h> // sockarrd_in,sockarrr_storage
#include <unistd.h> // functions to close the socket

int main (){
    int sock4=socket(AF_INET,SOCK_STREAM,0); // AFINET IS FOR IP4 USING TCP SOCKSTREAM , 0 DEFAULT 
    if (sock4<0){
        perror("IPv4 socket creation failed");
        return 1;
    }
    sockaddr_in addr4;
    memset(&addr4,0,sizeof(addr4));
    addr4.sin_family=AF_INET;
    addr4.sin_port=htons(3550);
    inet_pton(AF_INET,"127.0.0.1",&addr4.sin_addr);
    if (bind(sock4,(struct sockaddr*)&addr4,sizeof(addr4))<0){
        perror("ip4 bind failed");
        close (sock4);
        return 1;
    }
    std::cout << "IPv4 socket bound to 127.0.0.1:3550\n";
    
    int sock6=socket(AF_INET6,SOCK_STREAM,0);
    sockaddr_in6 addr6;
    memset(&addr6,0,sizeof(addr6));
    addr6.sin6_family=AF_INET6;
    addr6.sin6_port=htons(9090);
    inet_pton(AF_INET6,"::1",&addr6.sin6_addr);
    if (bind(sock6,(struct sockaddr*)&addr6,sizeof(addr6))<0){
        perror("IPv6 bind failed ");
        close(sock6);
        return 1;
    }
    sockaddr_storage storage;
    memset(&storage,0,sizeof(storage));
    memcpy(&storage,&addr4,sizeof(addr4));
    if (storage.ss_family==AF_INET){
        sockaddr_in *ip4ptr=(sockaddr_in*)&storage;
        char ipstr[INET_ADDRSTRLEN];
        std::cout << "sockaddr_storage holds IPv4 : "
                << ipstr << ":" << ntohs(ip4ptr->sin_port)<<"\n";
    }
    memcpy(&storage,&addr6,sizeof(addr6));
    if (storage.ss_family==AF_INET6){
        sockaddr_in6 *ip6ptr=(sockaddr_in6*)&storage;
        char ipstr6[INET6_ADDRSTRLEN];
        inet_ntop(AF_INET6,&ip6ptr->sin6_addr,ipstr6,INET6_ADDRSTRLEN);
        std::cout << "sockaddr_storage holds IPv6: "
            << ipstr6 << ":" << ntohs(ip6ptr->sin6_port)<<"\n";
    }
    std::cout << "size of sockarr_in is" << sizeof(sockaddr_storage) << std :: endl; 
    close(sock4);
    close(sock6);
return 0;
}

