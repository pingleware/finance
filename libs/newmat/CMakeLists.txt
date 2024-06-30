# libs/newmat/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(Newmat)

file(GLOB NEWMAT_SOURCES *.cpp)
file(GLOB NEWMAT_HEADERS *.h)

add_library(newmat STATIC ${NEWMAT_SOURCES})

target_include_directories(newmat PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
