cmake_minimum_required(VERSION 3.12)
project(simplyLinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(simplyLinkedList ../simpleLinkedList/src/main.cpp ../simpleLinkedList/src/classes/TEXT.cpp ../simpleLinkedList/src/header/TEXT.h ../simpleLinkedList/src/classes/EVKD.cpp ../simpleLinkedList/src/header/EVKD.h ../simpleLinkedList/src/header/main.h)