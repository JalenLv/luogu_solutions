cmake_minimum_required(VERSION 3.5)
project(my_app)

# make Clangd work with CMake
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

