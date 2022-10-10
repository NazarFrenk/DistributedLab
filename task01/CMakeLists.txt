cmake_minimum_required(VERSION 3.10)
project(task01)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE headers "include/*.h")
file(GLOB_RECURSE sources "src/*.cpp")

include_directories(
        ./src
        ./include
)

add_executable(task01 main.cpp ${headers} ${sources})