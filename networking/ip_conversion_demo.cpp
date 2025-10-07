#include <iostream> 
#include <arpa/inet.h>
#include <cstring>
#include <netinet/in.h>
int main (){
    const char* ipv4_text="10.12.110.57";
    struct sockaddr_in sa4;
    memset(&sa4,0,sizeof(sa4));
    int result=inet_pton(AF_INET,ipv4_text,&(sa4.sin_addr));
    if(result<=0){
        if (result==0){
            std::cerr<<"invalid ip4 address format\n";
        }
        else perror("inet_pton(IPv4) error");
        return 1;
    }
    std::cout << "[ipv4] string to binary conversion successful.\n";
    char ipv4_str[INET_ADDRSTRLEN];
    if(inet_ntop(AF_INET,&(sa4.sin_addr),ipv4_str,INET_ADDRSTRLEN)==nullptr){
        perror("inet_ntop(ipv4)error");
        return 1;
    }
    std::cout << "[IP4] Orginal : "<<ipv4_text << "\n";
    std::cout << "[IP4] converted back : " << ipv4_str << "\n\n";

    const char* ipv6_text="2001:db8:63b3:1::3434";
    struct sockaddr_in6 sa6;
    memset(&sa6,0,sizeof(sa6));
    result=inet_pton(AF_INET6,ipv6_text,&(sa6.sin6_addr));
     if(result<=0){
        if (result==0){
            std::cerr<<"invalid ip6 address format\n";
        }
        else perror("inet_pton(IPv6) error");
        return 1;
    }
     std:: cout << "result :: "<< result << std::endl;
    std::cout << "[ipv6] string to binary conversion succesful.\n";
    char ipv6_str[INET6_ADDRSTRLEN];
    if (inet_ntop(AF_INET6,&(sa6.sin6_addr),ipv6_str,INET6_ADDRSTRLEN)==nullptr){
        perror("inet_ntop (IPv6) error");
        return 1;
    }
    std::cout << "[IPv6] Original : " << ipv6_text << "\n";
    std::cout << "[IPv6] Converted back : " << ipv6_str << "\n";
    return 0;
}
