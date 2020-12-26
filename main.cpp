#include "Server/Server.h"
#include "Client/Client.h"
#include <thread>

void startServer() {
    Server server;
    server.listenAndAccept();
}

void startClient() {
    Client client;
}

int main() {


    thread serverThread(startServer);
    thread clientThread(startClient);
    if (serverThread.joinable()) {
        serverThread.join();
        cout << "SERVER - STOPPED" << endl;
    }
    if (clientThread.joinable()) {
        clientThread.join();
        cout << "CLIENT - STOPPED" << endl;
    }

    return 0;
}

