cmake_minimum_required(VERSION 3.17)
project(P2P_Terminal_Chat)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")
add_executable(P2P_Terminal_Chat
        main.cpp Server/Server.cpp Client/Client.cpp)
