#include <sys/types.h>
#include <sys/socket.h>
int bind(int sockfd,struct sockaddr *my_addr,int addrlen);

struct addrinfo hints{},*res;
int sockfd;
memset(&hints,0,sizeof hints);
hints.ai_family=AF_UNSPEC;
hints.ai_socktype=SOCK_STREAM;
hints.ai_flags=AI_PASSIVE;

getaddrinfo(NULL,"3490",&hints,&res);

sockfd=socket(res->ai_family,res->ai_socktype,res->protocol);

bind(sockfd,res->ai_addr,res->ai_addrlen);

// old way of doing :
int sockfd1;
struct sockaddr_in my_addr;
sockfd=socket(PF_INET,SOCK_STREAM,0);
my_addr.sin_famly=AF_INET;
my_addr.sin_port=htons(MYPORT);
my_addr.sin_addr.s_addr=inet_addr("10.12.110.57");
memset(my_addr.sin_zero,'\0',sizeof my_addr.sin_zero);
bind(sockfd1,(struct sockaddr*)&my_addr,sizeof my_addr);

int yes=1;
setsockopt(listner,SOL_SOCKET,SO_REUSEADDR,&yes.sizeof yes);

