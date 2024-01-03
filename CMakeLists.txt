cmake_minimum_required(VERSION 3.9)

project(dx-portfolio)

if (MSVC)
  add_compile_options(/source-charset:utf-8)
elseif (CMAKE_COMPILER_IS_GNUCXX)
  add_compile_options(-fexec-charset=UTF-8)
endif()

# Set
set(CMAKE_C_COMPILER "C:/Program Files/LLVM/bin/clang.exe")
set(CMAKE_CXX_COMPILER "C:/Program Files/LLVM/bin/clang++.exe")

set(CMAKE_EXPORT COMPILE_COMMANDS on)

set(INCLUDE_DIRECTORIES include)
set(SOURCE_DIRECTORIES src)
set(PRECOMPILE_DIRECTORIES pch)

set(PRECOMPILED_SOURCES
  ${PRECOMPILE_DIRECTORIES}/pch.h
)

set(PRECOMPILED_HEADERS
  ${PRECOMPILE_DIRECTORIES}/pch.h
)

set(SOURCES
  ${SOURCE_DIRECTORIES}/main.cc
  ${SOURCE_DIRECTORIES}/WindowsMessageMap.cpp
)

set(HEADERS
  ${INCLUDE_DIRECTORIES}/WindowsMessageMap.h
)

add_executable(dx-portfolio WIN32 ${SOURCES} ${HEADERS})

target_include_directories(dx-portfolio PUBLIC 
  ${CMAKE_SOURCE_DIR}/${INCLUDE_DIRECTORIES}
  ${CMAKE_SOURCE_DIR}/${PRECOMPILE_DIRECTORIES}
)

add_library(${PRECOMPILE_DIRECTORIES} INTERFACE)
target_precompile_headers(dx-portfolio PUBLIC ${PRECOMPILED_HEADERS})