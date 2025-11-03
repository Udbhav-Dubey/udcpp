#include <iostream>
#include <netdb.h>
#include <string>
#include <cstring>
#include <cstdlib.h>
#include <vector>
#include <arpa/inet.h>
#include <poll.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define PORT "9034"
class PollServer{
    private:
        int listener{};
        std::vector<pollfd> pfds;
    public:
        PollServer(){
            listener=create_listener_socket();
            if (listener==-1){
                throw std::runtime_error("Failed to create the listener socket ");
            }
            pollfd pfd{};
            pfd.fd=listener;
            pfd.events=POLLIN;
            pfds.push_back(pfd);
            std::cout << "Server now listining on port " << port << "\n";
        }
    void run(){
        while(true){
            int poll_count=poll(pfds.data(),pfds.size(),-1);
            if (poll_count==-1){
                perror("poll");
                exit(1);
            }
            for (size_t i=0;i<pfds.size();i++){
                if (pfds[i].revents&(POLLIN|POLHUP)){
                    
                }
            }
        }
    }
};
