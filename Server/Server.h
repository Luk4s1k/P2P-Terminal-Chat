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

#define PORT 8080

class Server {
private:
    int server;
    int client;
    int addrLength;
    char buffer[1024];

    struct sockaddr_in address;

    void bindSocket();


public:

    void listenAndAccept();

    Server()
    :addrLength(sizeof(address)){
        bindSocket();
    }

    ~Server() {
        close(server);
    };
};

#include "Server.cpp"

#endif //P2P_TERMINAL_CHAT_SERVER_H
