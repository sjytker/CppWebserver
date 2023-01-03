#include "Epoll.h"

int Epoll::add(int fd, int op, HttpRequest *request, int events)
{
    struct epoll_event ev;
    ev.data.ptr = (void *)request;
    ev.events = events;
    return epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, fd, ev);
}

int Epoll::mod(int fd, int op, HttpRequest *request)
{
    struct epoll_event ev;
    ev.data.ptr = (void *)request;
    ev.events = events;
    return epoll_ctl(epoll_fd_, EPOLL_CTL_MOD, fd, ev);
}

int Epoll::del(int fd, int op, HttpRequest *request)
{
    struct epoll_event ev;
    ev.data.ptr = (void *)request;
    ev.events = events;
    return epoll_ctl(epoll_fd_, EPOLL_CTL_DEL, fd, nullptr);
}

void Epoll:handleEvents(int socket_fd, ThreadPool *thread_pool) {
    
}