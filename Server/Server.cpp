#include "Server.h"
Server::Server()
        : addrLength(sizeof(address)) {
    bindSocket();
}

Server::~Server() {
    close(server);
}

void Server::bindSocket() {
    server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //If error occurs (socket() will return -1), printing error message & exit program;
    if (server == -1) {
        std::cerr << "Error while creating socket." << std::endl << std::strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT); //Temporarily port. Need to discuss

    //If error occurs (bind() will return -1), printing error message & exit program;
    if (bind(server, (struct sockaddr *) &address, addrLength) == -1) {
        std::cerr << "Error while binding socket." << std::endl << std::strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Server::listenAndAccept() {

    listen(server, 0);
    client = accept(server, (struct sockaddr *) nullptr, nullptr);
    //If error occurs (accept will return -1), printing error message & exit program;
    if (client == -1) {
        std::cerr << "Error while accepting the connection. " << std::endl << std::strerror(errno) << std::endl;
        std::cerr << "Connection refused." << std::endl;
        exit(EXIT_FAILURE);
    }

    //Receive data from client and store it into buffer
    read(client, buffer, sizeof(buffer));
    std::cout << buffer << std::endl;
    //Sends a confirmation of receipt of the message to the client;
    write(client, "Received", sizeof("Received"));

}

