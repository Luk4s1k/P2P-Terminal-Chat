#ifndef P2P_TERMINAL_CHAT_SERVER_H
#define P2P_TERMINAL_CHAT_SERVER_H

#include <iostream>
#include <cstdio>
#include <cerrno>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <cstring>

#define PORT 8813

class Server {
private:
    int server;
    int client;
    int addrLength;
    char buffer[1024];
    struct sockaddr_in address;
    std::string userName;

    void bindSocket();

public:
    Server();
    ~Server();
    void listenAndAccept();
};


#endif //P2P_TERMINAL_CHAT_SERVER_H
