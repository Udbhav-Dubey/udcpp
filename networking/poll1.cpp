#include <iostream>
#include <poll.h>
int main (){
    struct pollfd pfds[1];
    pfds[0].fd=0;
    pfds[0].events=POLLIN;
    pfds[0].revents=0;
    std::cout << "Hit Return or wait 2.5 seconds for timeout\n";
    int num_events=poll(pfds,1,2500);
    if (num_events==-1){
        perror("poll");
        return 1;
    }
    if (num_events==0){
        std::cout << "Poll timed\n";
    }
    else {
        if (pfds[0].revents&POLLIN){
            std::cout << "File Descriptor " << pfds[0].fd << "is ready to read \n";
        }
        else {
            std::cout << "Unexpected event : " << pfds[0].revents <<"\n";
        }
    }
    return 0;
}
