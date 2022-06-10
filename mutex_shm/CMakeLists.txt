cmake_minimum_required(VERSION 3.21)
project(processThread)

set(CMAKE_CXX_STANDARD 14)

add_executable(client shm_client.cpp )
target_link_libraries(client -lpthread )

add_executable(server shm_server.cpp )

target_link_libraries(server -lpthread )
