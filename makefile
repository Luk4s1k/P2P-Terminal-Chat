
CC = g++ -Wall -Werror -pthread
CLIENT_PART = ./Client/Client.cpp
SERVER_PART = ./Server/Server.cpp
BIN = ./bin/chat

all:
	${CC} ${CLIENT_PART} ${SERVER_PART} main.cpp -o ${BIN}
