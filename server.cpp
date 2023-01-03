#include "server.h"

#include <iostream>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

Server::Server(int port, char *addr, int thread_num)
    : port_(port), addr_(addr), thread_num_(thread_num)
{
    if ((socket_fd_ = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0)) < 0)
    {
        std::cout << "create socket_fd fail" << std::endl;
        exit(1);
    }
    struct sockaddr_in sa_server;
    sa_server.sin_family = AF_INET;
    // sa_server.sin_addr.s_addr = inet_addr(addr);
    sa_server.sin_addr.s_addr = htonl(INADDR_ANY);
    sa_server.sin_port = htons((unsigned short)port);
    // std::cout << addr << ' ' << inet_addr(addr) << std::endl;
    if (bind(socket_fd_, (sockaddr *)&sa_server, sizeof(sa_server)) < 0)
    {
        std::cout << "[Server] bind fail" << std::endl;
        exit(1);
    }

    if(listen(socket_fd_, SOMAXCONN) == -1) {
        std::cout << "[Server] listen fd fail)" << std::endl;
        exit(1);
    }

    epoll_ = new Epoll();
}

void Server::run()
{
    int clfd, status;
    pid_t pid;

    for (;;)
    {
        
    }
}
