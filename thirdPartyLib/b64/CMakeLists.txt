cmake_minimum_required(VERSION 3.7)
project(b64)
file(GLOB C_SOURCES *.c)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
add_library(b64 STATIC ${C_SOURCES})
