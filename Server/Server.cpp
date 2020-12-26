#include "Server.h"

void Server::bindSocket() {
    server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server == -1) {
        std::cerr << "Error while creating socket." << std::endl << std::strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT); //Temporarily port. Need to discuss

    if (bind(server, (struct sockaddr *) &address, addrLength) == -1) {
        std::cerr << "Error while binding socket." << std::endl << std::strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
}

int Server::listenAndAccept() {

    listen(server, 0);
    client = accept(server, (struct sockaddr *) nullptr, nullptr);
    if (client == -1) {
        std::cerr << "Error while accepting the connection. " << std::endl << std::strerror(errno) << std::endl;
        std::cerr << "Connection refused." << std::endl;
        exit(EXIT_FAILURE);
    }
    read(client, buffer, sizeof(buffer));
    std::cout << buffer << std::endl;
    write(client, "Received", sizeof("Received"));

    close(server);
    return 0;
}