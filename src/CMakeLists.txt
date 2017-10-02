add_library(Str Str.h Str.cpp)
add_executable(str_cpp main.cpp)
target_link_libraries(str_cpp Str)
