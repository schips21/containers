cmake_minimum_required(VERSION 3.17)
project(git_containers)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(git_containers
        list_test.cpp
        vector_test.cpp
        map_test.cpp
        queue_test.cpp
        stack_test.cpp
        main.cpp)
