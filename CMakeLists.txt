cmake_minimum_required(VERSION 3.12)
project(ex2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex2
        ex2.cpp
        LList.h
        LList.tcc
        StringC.cpp
        StringC.h)
