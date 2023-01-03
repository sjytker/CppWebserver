#include "Epoll.h"

#include <errno.h>
#include <string>

#include <sys/socket.h>

class Server
{
public:
    Server(int port, char *addr, int thread_num);

    void run();

private:
    int port_;
    int thread_num_;
    int socket_fd_;
    int epoll_fd_;
    char *addr_;
    Epoll epoll_;
};