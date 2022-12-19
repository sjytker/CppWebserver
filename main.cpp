// #include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
// #include<cppwebserver.h>
// #include<errno.h>
// #include<sys/socket.h>
// #include<server.h>
using namespace std;


void print_usage() {
    cout << "Usage: [-p port] [-a address].  Default port is 6000. Default addr is localhost." << endl; 
}

int main(int argc, char *argv[]) {
    // int port = PORT, thread_num = TRHEAD_NUMS;
    // string address = ADDRESS;
    int port = 6000, thread_num = 4;
    string address = "127.0.0.1";

    if (argc > 1 && strcmp(argv[1], "-h") == 0) {
        print_usage();
        exit(1);
    }
    if (argc <=5 && (argc % 2 == 1)) {
        for (int i = 1; i < argc; i += 2) {
            char *s = argv[i];
            if (strcmp(s, "-p") == 0) port = atoi(argv[i + 1]);
            else if (strcmp(s, "-a") == 0) address = string(argv[i + 1]);
            else {
                print_usage();
                exit(EXIT_FAILURE);
            }
        }
    } else {
        print_usage();
    }

    Server server = Server(port, address, thread_num);
    // server.run();   
    return 0;
}