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

set(C_LINKED_LIST_LIB c_singly_linked_list)
add_library(${C_LINKED_LIST_LIB} STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/singly_linked_list.c
    # Header not required for compilation, adding only for IDE visibility
    ${CMAKE_CURRENT_SOURCE_DIR}/singly_linked_list.c
)
# Correct include directories (use the folder, not the header file)
target_include_directories(${C_LINKED_LIST_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Define the executable with source files
add_executable(${EXE_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(${EXE_NAME} PRIVATE ${C_LINKED_LIST_LIB})
target_include_directories(${EXE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
