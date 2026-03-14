cmake_minimum_required(VERSION 3.20)
project (eseguies1.8)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCES esercizio1.8.cpp)
add_executable(eseguies1.8 ${SOURCES})
