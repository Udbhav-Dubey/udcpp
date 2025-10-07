struct sockaddr_in sa;
inet_pton(AF_INET,"10.12.110.57",&(sa.sin_addr));

int result=inet_pton(AF_INET,"10.12.110.57",&(sa.sin_addr));
if (result<=0){
    if (result==0){
    std::cerr<<"invalid address format\n";
        }
    else {perror("inet_pton error");}
}

char ip4[INET_ADDRSTRLEN];
inet_ntop(AF_INET,&(sa.sin_addr),ip4,INET_ADDRSTRLEN);
std :: cout << "ip4 address is : " << ip4 << "\n";


struct sockaddr_in6 sa6;
inet_pton(AF_INET6,"2001:db8:64b3:1::3490",&(sa6.sin6_addr));

char ip6[INET6_ADDRSTRLEN];
inet_ntop(AF_INET6,&(sa6.sin6_addr),ip6,INET6_ADDRSTRLEN);
std::cout << "IPv6 address is : " << ip6 << "\n";
