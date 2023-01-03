#include <sys/epoll.h>

#include <cassert>
#include <vector>

class Epoll
{
public:
    Epoll()
    {
        epoll_fd_ = epoll_create1(EPOLL_CLOEXEC);
        assert(epoll_fd_ >= 0);
    }

    int add(int fd, int op, HttpRequest *request);
    int mod(int fd, int op, HttpRequest *request);
    int del(int fd, int op, HttpRequest *request);

private:
    int epoll_fd_;
    std::vector<struct epoll_event> events;
};