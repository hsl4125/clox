cmake_minimum_required(VERSION 3.20)

project(CLox)
set(CMAKE_C_STANDARD 99)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(compiler)
add_subdirectory(repl)

