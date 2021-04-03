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

int main(int argc, char *argv[]) {

    //Open two threads for Server and Client to work parallel
    std::thread serverThread(startServer);
    std::thread clientThread(startClient);

    //Join threads if joinable()
    if (serverThread.joinable()) {
        serverThread.join();
    }
    if (clientThread.joinable()) {
        clientThread.join();
    }

    return 0;
}
