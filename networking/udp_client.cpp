#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main (){
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) { perror("socket"); return 1; }

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(3030);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    std::string msg = "Hello UDP server!";
    sendto(sockfd, msg.c_str(), msg.size(), 0,
           (sockaddr*)&server_addr, sizeof(server_addr));

    char buffer[1024];
    sockaddr_storage sender_addr{};
    socklen_t sender_len = sizeof(sender_addr);

    int bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0,
                                  (sockaddr*)&sender_addr, &sender_len);
    if (bytes_received > 0) {
        std::cout << "Server says: " << std::string(buffer, bytes_received) << "\n";
    }

    close(sockfd);
    return 0;
}
