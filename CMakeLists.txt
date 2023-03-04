cmake_minimum_required(VERSION 3.22)
project(crypto
    LANGUAGES CXX
)

# guard against in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

find_package(Boost REQUIRED)

add_subdirectory(lib)
add_subdirectory(example)