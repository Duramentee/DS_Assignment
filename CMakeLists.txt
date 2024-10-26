cmake_minimum_required(VERSION 3.28.3)
project(ds)

set(CMAKE_CXX_STANDARD 23)

add_executable(ds DoublyLinkedList/DoublyLinkedList.cpp
        DoublyLinkedList/DoublyLinkedList.cpp
        ref.cpp
        DoublyLinkedList/DoublyLinkedList.h)
