cmake_minimum_required(VERSION 3.10.0)
project(linked_list)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(EXE_NAME ${PROJECT_NAME}_dbg)
else()
    set(EXE_NAME ${PROJECT_NAME})
endif()

# Define the executable with source files
add_executable(${EXE_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

# Correct include directories (use the folder, not the header file)
target_include_directories(${EXE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
