#include <iostream>
#include <poll.h>
#include <unistd.h>
int main (){
    struct pollfd pfds[1];
    pfds[0].fd=STDIN_FILENO;
    pfds[0].events=POLLIN;
    std::cout << "Press enter within 2.5 seconds : ";
    int num_events=poll(pfds,1,250000);
    if (num_events==0){
        std::cout << "timeout no input recieved : \n";
    }
    else if (pfds[0].revents&POLLIN){
        std::cout << "Data ready to read on stdin!\n";
    }
    return 0;
}
