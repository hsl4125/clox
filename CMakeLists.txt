cmake_minimum_required(VERSION 3.20)

project(CLox)
set(CMAKE_C_STANDARD 99)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE HEADER_FILES *.h)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${HEADER_FILES})

add_definitions("-Wall -g")


add_subdirectory(compiler)
add_subdirectory(repl)

