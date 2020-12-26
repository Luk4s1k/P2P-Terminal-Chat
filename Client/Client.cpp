#include "Client.h"
#include <iostream>

Client::Client() {
    string buffer = "Hello from client(Matvey)";
    connectToServer(SERVERIP, SERVERPORT);
    sendMessage(buffer);
}

void Client::connectToServer(const char *serverIP, int port) {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_addr.s_addr = inet_addr(serverIP);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVERPORT);

    if (connect(serverSocket, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
        cout << "Successful connection to server " << serverIP << endl;
    } else {
        cout << "Connection refused! " << endl;
    }


}

void Client::sendMessage(string buffer) {
    write(serverSocket, buffer.c_str(), sizeof(buffer));   // converts string buffer into char array
    cout << "Message was sent!" << endl;
    char valread[1025] = {0};                               // receiving value from server
    read(serverSocket, valread, sizeof(valread));
    cout << valread << endl;
}