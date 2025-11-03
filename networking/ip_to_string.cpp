#include <iostream>
#include <arpa/inet.h>
#include <iostream>
std::string ipToString(sockaddr_storage*addr){
    char buf[INET6_ADDRSTRLEN];
    if (addr->ss_family==AF_INET){
        inet_ntop(AF_INET,&((sockaddr_in*)addr)->sin_addr,buf,sizeof(buf));
    }
    else {
    inet_ntop(AF_INET6,&((sockaddr_in6*)addr)->sin6_addr,buf,sizeof(buf));
    }
    return std::string(buf);
}
