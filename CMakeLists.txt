cmake_minimum_required(VERSION 3.26)
project(BinarySearchTreeSFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(BinarySearchTreeSFML main.cpp
        Application.cpp
        Application.h
        TreeType.h
        Button.cpp
        Button.h
        BinarySearchTree.cpp
        BinarySearchTree.h
        AVLTree.cpp
        AVLTree.h
        TraversalType.h
        Node.cpp
        Node.h
        Helper.cpp
        Helper.h
        BTree.cpp
        BTree.h
)
target_link_libraries(BinarySearchTreeSFML sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
file(COPY "arial.ttf" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
