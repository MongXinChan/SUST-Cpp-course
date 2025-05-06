# CMake minimum version
cmake_minimum-required(VERSION 3.10)

# Project name
project(CMakeDemo4)

# Search the source files in the current directory
# and store them in the variable DIR_SRCS
aux_source_directory(. DIR_SRCS)

# add the directory of include
include_directories(lib)

# Specify the subdirectory of lib
add_subdirectory(lib)

# Specify the build target
add_executable(CMakeDemo4 ${DIR_SRCS})

# Link the library to the executable
target_link_libraries(CMakeDemo4 MyFunction)
