#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
#include <algorithm>

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include <sys/socket.h>
#include <netdb.h>
#include <poll.h>

constexpr const char* PORT = "9090";
constexpr int BACKLOG = 10;
constexpr int BUF_SIZE = 4096;

/* ---------- Utility ---------- */

void set_nonblocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

/* ---------- Client State ---------- */

struct Client {
    int fd;
    std::string read_buffer;
    std::string write_buffer;
};

/* ---------- Main ---------- */

int main() {
    /* ---- getaddrinfo ---- */
    addrinfo hints{}, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family   = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE;

    if (getaddrinfo(nullptr, PORT, &hints, &res) != 0) {
        perror("getaddrinfo");
        return 1;
    }

    /* ---- socket ---- */
    int listener = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (listener < 0) {
        perror("socket");
        return 1;
    }

    int yes = 1;
    setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
    set_nonblocking(listener);

    /* ---- bind ---- */
    if (bind(listener, res->ai_addr, res->ai_addrlen) < 0) {
        perror("bind");
        return 1;
    }
    freeaddrinfo(res);

    /* ---- listen ---- */
    if (listen(listener, BACKLOG) < 0) {
        perror("listen");
        return 1;
    }

    std::cout << "Poll server listening on port " << PORT << "\n";

    /* ---- poll structures ---- */
    std::vector<pollfd> poll_fds;
    std::unordered_map<int, Client> clients;

    poll_fds.push_back({
        .fd = listener,
        .events = POLLIN,
        .revents = 0
    });

    /* ---------- Event Loop ---------- */

    while (true) {
        int ready = poll(poll_fds.data(), poll_fds.size(), -1);
        if (ready < 0) {
            if (errno == EINTR) continue;
            perror("poll");
            break;
        }

        for (size_t i = 0; i < poll_fds.size(); i++) {
            pollfd &pfd = poll_fds[i];

            if (pfd.revents == 0)
                continue;

            /* ---- New connection ---- */
            if (pfd.fd == listener && (pfd.revents & POLLIN)) {
                while (true) {
                    sockaddr_storage addr;
                    socklen_t len = sizeof(addr);

                    int client_fd = accept(listener, (sockaddr*)&addr, &len);
                    if (client_fd < 0) {
                        if (errno == EAGAIN || errno == EWOULDBLOCK)
                            break;
                        perror("accept");
                        break;
                    }

                    set_nonblocking(client_fd);

                    poll_fds.push_back({
                        .fd = client_fd,
                        .events = POLLIN,
                        .revents = 0
                    });

                    clients[client_fd] = Client{client_fd};

                    std::cout << "New client: fd=" << client_fd << "\n";
                }
                continue;
            }

            /* ---- Error / hangup ---- */
            if (pfd.revents & (POLLHUP | POLLERR | POLLNVAL)) {
                close(pfd.fd);
                clients.erase(pfd.fd);

                poll_fds.erase(
                    std::remove_if(poll_fds.begin(), poll_fds.end(),
                        [&](const pollfd& x) { return x.fd == pfd.fd; }),
                    poll_fds.end()
                );
                i--;
                continue;
            }

            /* ---- Read ---- */
            if (pfd.revents & POLLIN) {
                char buf[BUF_SIZE];

                ssize_t n = recv(pfd.fd, buf, sizeof(buf), 0);
                if (n == 0) {
                    close(pfd.fd);
                    clients.erase(pfd.fd);

                    poll_fds.erase(
                        std::remove_if(poll_fds.begin(), poll_fds.end(),
                            [&](const pollfd& x) { return x.fd == pfd.fd; }),
                        poll_fds.end()
                    );
                    i--;
                    continue;
                }

                if (n < 0) {
                    if (errno != EAGAIN) {
                        close(pfd.fd);
                        clients.erase(pfd.fd);
                    }
                    continue;
                }

                Client &c = clients[pfd.fd];
                c.read_buffer.append(buf, n);

                /* Echo protocol (replace with HTTP later) */
                c.write_buffer += c.read_buffer;
                c.read_buffer.clear();

                pfd.events |= POLLOUT;
            }

            /* ---- Write ---- */
            if (pfd.revents & POLLOUT) {
                Client &c = clients[pfd.fd];

                ssize_t sent = send(
                    pfd.fd,
                    c.write_buffer.data(),
                    c.write_buffer.size(),
                    0
                );

                if (sent < 0) {
                    if (errno != EAGAIN) {
                        close(pfd.fd);
                        clients.erase(pfd.fd);
                    }
                    continue;
                }

                c.write_buffer.erase(0, sent);

                if (c.write_buffer.empty()) {
                    pfd.events &= ~POLLOUT;
                }
            }
        }
    }

    close(listener);
    return 0;
}

