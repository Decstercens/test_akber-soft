cmake_minimum_required(VERSION 3.0)

project(test_akber-soft)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "")
set(CMAKE_C_COMPILER /usr/bin/gcc)

set(INCLUDE_DIR lib)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/hash.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

include_directories(${INCLUDE_DIR})

set(SOURCES
    ${INCLUDE_DIR}/file_work.h
    ${INCLUDE_DIR}/hash_item.h
    ${INCLUDE_DIR}/read_string.h

    src/fileWork.c
    src/hashItem.c
    src/readString.c
    src/saveStringAsHash.c)
    
add_executable(storage ${SOURCES})