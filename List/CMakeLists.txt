cmake_minimum_required(VERSION 3.16)
project(list VERSION 1)
list(APPEND singleList SingleList/SingleList.cpp SingleList/SingleList.h )
add_executable(main main.cpp ${singleList})