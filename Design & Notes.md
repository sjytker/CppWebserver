## InitServer
1. Create socket, bind and listen locally.
2. Loop the epoll_wait with timeout.


## About Sockaddr when using bind
- Programmers should not operate SOCKADDR,SOCKADDR is for the operating system.
- Programmers should use sockaddr_in to represent addresses, sockaddr_in distinguish between addresses and ports, and are more convenient to use.

## Reactor (Epoll)
- The Epoll module just focus on epoll's create, modify, wait.
- Split other logics into other modules. They will be called as Callback Function.

