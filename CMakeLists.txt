cmake_minimum_required(VERSION 3.16)

project(pro_name VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 REQUIRED)

#core

add_library(
    core
    src/core/core.cpp
)

target_include_directories(
    core
    PUBLIC
    src/core
)


#platform

add_library(
    platform
    src/platform/Sdl.cpp
)

target_include_directories(
    platform
    PUBLIC
    src/platform
)

target_link_libraries(
    platform
    PRIVATE 
    SDL2::SDL2
)

#exe

add_executable(
    pro_name
    src/main.cpp
)

target_include_directories(
    pro_name 
    PRIVATE 
    src/core
    src/platform
)

target_link_libraries(
    pro_name 
    PRIVATE 
    core
    platform
)

target_compile_options(
    pro_name 
    PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)