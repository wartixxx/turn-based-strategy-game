cmake_minimum_required(VERSION 3.20)
project(tbs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(game
    src/main.cpp
)

target_include_directories(game PRIVATE include)

