cmake_minimum_required(VERSION 3.18)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(foo VERSION 1.0.0)

# List or Group CMAKE
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(cmake/dependency.cmake)
include(cmake/package.cmake)

add_subdirectory(src)
add_subdirectory(tests)
