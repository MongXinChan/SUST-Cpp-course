# CMake minimum required version
cmake_minimum_required(VERSION 3.10)

# project information
project(hello)

# Search the source files in the src directory
# and store them into the variable DIR_SRCS
aux_source_directory(./src DIR_SRCS)

# aux_source_directory(<dir> <variable>)
# 将src目录下的所有源文件存储到变量DIR_SRCS中

# add the directory of include files
include_directories(./include)


# 添加可执行文件
add_executable(hello ${DIR_SRCS})
# add_executable(hello main.cpp factorial.cpp printhello.cpp)  ERROR
# add_executable(hello src/main.cpp src/factorial.cpp src/printhello.cpp)  right relative path~
