
cmake_minimum_required(VERSION 2.8.9)
project(Chat)
include_directories(include)
set(SOURCES src/main.cpp)
add_executable(Server ${SOURCES})