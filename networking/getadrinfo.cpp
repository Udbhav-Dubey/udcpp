#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
int getaddrinfo(const char*node,const char*service,const struct addrinfo*hints,struct addrinfo**res);
int getaddrinfo(NULL,"3490",&hints,&serverinfo);

int getaddrinfo("www.google.com","3491",&hints,&serverinfo);


int status;
struct addrinfo hints;
struct addrinfo *serverinfo

memset(*hints,0,sizeof hints);
hints.ai_family=AF_UNSPEC;
hints.ai_socktype=SOCK_STREAM;
hints.ai_flags=AI_PASSIVE;

if ((status=getaddrinfo(NULL,"3490",&hints,&serverinfo))!=0){
    perror("gai error");
    exit(1);
}
freeaddrinfo(serverinfo);
