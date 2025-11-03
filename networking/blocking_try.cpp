#include <unistd.h>
#include <fcntl.h>
sockfd=socket(PF_INET,SOCK_STREAM,0);
fcntl(socfd,F_SETFL,O_NONBLOCK);
