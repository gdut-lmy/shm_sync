cmake_minimum_required(VERSION 3.21)
project(processThread)

set(CMAKE_CXX_STANDARD 14)

add_executable(read basic_shm/read_shm.cpp)

add_executable(write basic_shm/write_shm.cpp)
