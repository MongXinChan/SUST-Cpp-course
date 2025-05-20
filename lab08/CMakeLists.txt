cmake_minimum_required(VERSION 3.12)
project(simd_openmp_lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加源文件
add_executable(my_program main.cpp matoperation.cpp)

# --- SIMD 配置 ---
# 检查 AVX2 支持 (示例，实际检查可能更复杂)
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-mavx2" COMPILER_SUPPORTS_AVX2)

if(COMPILER_SUPPORTS_AVX2)
    message(STATUS "AVX2 is supported by the compiler.")
    target_compile_options(my_program PRIVATE -mavx2)
    target_compile_definitions(my_program PRIVATE WITH_AVX2)
else()
    message(WARNING "AVX2 is not supported by the compiler.")
endif()

# --- OpenMP 配置 ---
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    message(STATUS "OpenMP found.")
    target_link_libraries(my_program PUBLIC OpenMP::OpenMP_CXX)
else()
    message(WARNING "OpenMP not found.")
endif()

# --- 优化级别 ---
target_compile_options(my_program PRIVATE -O3)