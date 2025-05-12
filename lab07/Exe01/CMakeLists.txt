cmake_minimum_required(VERSION 3.10)
project(Exe01)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加头文件目录
include_directories(include)

# 添加 src 子目录
add_subdirectory(src)

# 添加可执行文件
add_executable(main src/main.cpp)
target_link_libraries(main vabs)