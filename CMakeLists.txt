cmake_minimum_required(VERSION 3.28.3)
project(test.out)

set(CMAKE_CXX_STANDARD 23)

find_package(GTest)

add_executable(test.out DoublyLinkedList/DoublyLinkedList.hpp
        main.cpp)

target_link_libraries(test.out GTest::gtest GTest::gtest_main)