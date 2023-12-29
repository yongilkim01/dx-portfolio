cmake_minimum_required(VERSION 3.9)

project(dx-portfolio)

# GCC로 설정
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

set (SOURCES src/main.cc)

add_definitions(-DUNICODE -D_UNICODE)

add_executable(dx-portfolio WIN32 ${SOURCES})

set( CMAKE_EXPORT COMPILE_COMMANDS on )