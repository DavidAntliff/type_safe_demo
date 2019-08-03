cmake_minimum_required(VERSION 3.14)
project(type_safe_demo)

set(CMAKE_CXX_STANDARD 14)

add_executable(type_safe_demo main.cpp)

add_subdirectory(debug_assert)
add_subdirectory(type_safe)
target_link_libraries(type_safe_demo PUBLIC debug_assert type_safe)
