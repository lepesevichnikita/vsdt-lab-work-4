cmake_minimum_required(VERSION 3.13)

add_executable(lab4
  main.cpp
  task1.cpp
)

target_include_directories(lab4 PRIVATE ${INCLUDE_DIR})
