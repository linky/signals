cmake_minimum_required(VERSION 3.0)

project(test_basic)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} signals)
