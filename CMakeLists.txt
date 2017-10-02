cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

project(str_cpp)

add_subdirectory(src)

enable_testing()
add_subdirectory(tst)
