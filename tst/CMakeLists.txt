add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE catch.hpp)

add_executable(tst main.cpp)
target_link_libraries(tst Catch Str)
