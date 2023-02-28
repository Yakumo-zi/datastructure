cmake_minimum_required(VERSION 3.16)
project(tree VERSION 1)
list(APPEND binaryTree BinaryTree/BinaryTree.h BinaryTree/BinaryTree.cpp)
add_executable(main main.cpp ${binaryTree})