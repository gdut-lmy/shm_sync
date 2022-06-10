cmake_minimum_required(VERSION 3.21)
project(processThread)

set(CMAKE_CXX_STANDARD 14)

add_executable(write write.cpp )
target_link_libraries(write -lpthread )

add_executable(read read.cpp )

target_link_libraries(read -lpthread )


