cmake_minimum_required(VERSION 2.6)
set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(binaryTree main.cpp Node.cpp Node.hpp Tree.cpp Tree.hpp)
target_link_libraries(binaryTree ${GTEST_LIBRARIES} pthread)
