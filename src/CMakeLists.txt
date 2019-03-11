cmake_minimum_required(VERSION 3.13)

add_executable(main
  main.cpp
  task1.cpp
  task3.cpp
  task4.cpp
)

target_include_directories(main PRIVATE ${INCLUDE_DIR})
