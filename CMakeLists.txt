cmake_minimum_required(VERSION 3.13)

project(lab4)

set(PROJECT_BINARY_DIR build)
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

add_subdirectory(src build)

include_directories(${PROJECT_BINARY_DIR})
