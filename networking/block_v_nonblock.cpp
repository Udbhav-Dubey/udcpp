#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <cstring>
#include <cerrno>

int main() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    std::cout << "Blocking socket: waiting for data...\n";
    char buf[1024];

    ssize_t n = recvfrom(sockfd, buf, sizeof(buf) - 1, 0, nullptr, nullptr);
    if (n > 0) {
        buf[n] = '\0';
        std::cout << "Received: " << buf << "\n";
    }

    fcntl(sockfd, F_SETFL, O_NONBLOCK);
    std::cout << "\nNon-blocking mode: trying recvfrom() again...\n";

    n = recvfrom(sockfd, buf, sizeof(buf) - 1, 0, nullptr, nullptr);
    if (n < 0) {
        if (errno == EAGAIN || errno == EWOULDBLOCK)
            std::cout << "No data available (EWOULDBLOCK)\n";
        else
            perror("recvfrom");
    } else {
        buf[n] = '\0';
        std::cout << "Received: " << buf << "\n";
    }

    close(sockfd);
    return 0;
}

