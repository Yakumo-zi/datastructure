cmake_minimum_required(VERSION 3.16)
project(list VERSION 1)
list(APPEND singleList SingleList/SingleList.cpp SingleList/SingleList.h )
list(APPEND stack Stack/Stack.cpp Stack/Stack.h)
list(APPEND queue Queue/Queue.cpp Queue/Queue.h)
list(APPEND practice practice.h practice.cpp)
list(APPEND selfAdjustingTable SelfAdjustingTable/SelfAdjustingTable.h SelfAdjustingTable/SelfAdjustingTable.cpp)
add_executable(main main.cpp ${practice} ${singleList} ${stack} ${queue} ${selfAdjustingTable})