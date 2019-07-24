cmake_minimum_required(VERSION 3.14)
project(type_safe_demo)

set(CMAKE_CXX_STANDARD 14)

add_executable(type_safe_demo main.cpp)

add_subdirectory(debug_assert)
add_subdirectory(type_safe)
#target_include_directories(type_safe_demo PRIVATE type_safe_demo/include)
#target_include_directories(type_safe_demo PRIVATE debug_assert)
