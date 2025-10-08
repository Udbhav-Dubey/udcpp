int sockfd=socket(AF_INET,SOCK_STREAM,0);

struct addrinfo hints{},*res;
hints.ai_family=AF_UNSPEC;
hints.ai_socktype=SOCK_STREAM;

int status=getaddrinfo("www.example.com","http",&hints,*res);
if (status!=0){
    std::cerr<<"getaddrinfo: " <<gai_strerror(status) << "\n";
    return 1;
}
int sockfdd=socket(res->ai_family,res->ai_socktype,res->ai_protocol);
