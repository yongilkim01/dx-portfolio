cmake_minimum_required(VERSION 3.9)

project(dx-portfolio)

# GCC로 설정
set(CMAKE_C_COMPILER "C:/Program Files/LLVM/bin/clang.exe")
set(CMAKE_CXX_COMPILER "C:/Program Files/LLVM/bin/clang++.exe")

add_compile_options(-fexec-charset=UTF-8)

if (MSVC)
    add_compile_options(/source-charset:utf-8)
elseif (CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-fexec-charset=UTF-8)
endif()

set (SOURCES src/main.cc)

add_definitions(-DUNICODE -D_UNICODE)

add_executable(dx-portfolio WIN32 ${SOURCES})

set( CMAKE_EXPORT COMPILE_COMMANDS on )
