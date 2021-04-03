#ifndef P2P_TERMINAL_CHAT_CLIENT_H
#define P2P_TERMINAL_CHAT_CLIENT_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <map>
#include <string>


#define SERVERIP "156.17.224.165"
#define SERVERPORT 8083

class Client {
    int serverSocket;
    struct sockaddr_in addr;
    std::string userName;
    std::string message;

public:
    Client();
    ~Client();
    void connectToServer(const char *serverIP, int port );
    void sendMessage();
};




#endif //P2P_TERMINAL_CHAT_CLIENT_H
