cmake_minimum_required(VERSION 3.26)
project(BinarySearchTreeSFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(BinarySearchTreeSFML main.cpp
        BinarySearchTree.cpp
        BinarySearchTree.h
        Button.cpp
        Button.h
        Node.h)
target_link_libraries(BinarySearchTreeSFML sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
file(COPY "arial.ttf" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
