cmake_minimum_required(VERSION 3.15)

project(test-child-debug)

add_library(rapidjson INTERFACE)
target_include_directories(rapidjson INTERFACE rapidjson/include)

add_executable(parent parent/main.cpp)
target_link_libraries(parent PRIVATE rapidjson)
add_executable(child child/main.cpp)
target_link_libraries(child PRIVATE rapidjson)
add_dependencies(parent child) # so parent can CreateProcess child
