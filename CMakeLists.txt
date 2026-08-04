cmake_minimum_required(VERSION 3.16)

project(Donut VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 REQUIRED)

add_executable(
    Donut
    src/main.cpp
)

target_include_directories(Donut PRIVATE src)

target_link_libraries(Donut PRIVATE SDL2::SDL2)

target_compile_options(Donut PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)