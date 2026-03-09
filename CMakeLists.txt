cmake_minimum_required(VERSION 3.8)
project(ITaP_tests)

set(CMAKE_CXX_STANDARD 20)

add_executable(ITaP_tests main.cpp
        utils.cpp
        utils.h
        task_1.cpp
        task_1.h
        console_interface.cpp
        console_interface.h
)
