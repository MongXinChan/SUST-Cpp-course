# CMake minimum version
cmake_minimum_required(VERSION 3.10)

# project information
project(CMakeDemo5)

# Search the source files in the current directory
# and store them into the variable DIR_SRCS
aux_source_directory(. DIR_SRCS)

# add the directory of include
include_directories(lib)

# add the subdirectory of lib
add_subdirectory(lib)

# Specify the build target
add_executable(CMakeDemo5 ${DIR_SRCS})

# Add the dynamic library
target_link_libraries(CMakeDemo5 MyDynamicFun)