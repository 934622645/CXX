cmake_minimum_required(VERSION 3.16)
project(start)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)
include_directories(Calculate)

add_executable(start ${SOURCE_FILES})

add_subdirectory(Calculate)
add_subdirectory(Google_tests)
