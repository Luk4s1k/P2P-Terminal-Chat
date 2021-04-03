#include "Client.h"
#include <iostream>

Client::Client()
        :userName("Client") {
    connectToServer(SERVERIP, SERVERPORT);
    sendMessage();
}

Client::~Client() {
    close(serverSocket);
    std::cout << "CLIENT - STOPPED" << std::endl;
}

void Client::connectToServer(const char *serverIP, int port) {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_addr.s_addr = inet_addr(serverIP);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVERPORT);

    if (connect(serverSocket, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
        std::cout << "Successful connection to server " << serverIP << std::endl;
    } else {
        std::cout << "Connection refused! " << std::endl;
    }

}

void Client::sendMessage() {
    std::cout << "MSG: ";
    getline(std::cin, message);
    // converts string buffer into char array & sending
    write(serverSocket, message.c_str(), sizeof(message));
    std::cout << "Message was sent!" << std::endl;
    // receiving value from server
    char valread[1025] = {0};
    read(serverSocket, valread, sizeof(valread));
    std::cout << valread << std::endl;
}
