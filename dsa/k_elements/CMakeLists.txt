cmake_minimum_required(VERSION 3.10.0)
project(k_elements)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(EXE_NAME ${PROJECT_NAME}_dbg)
else()
    set(EXE_NAME ${PROJECT_NAME})
endif()

add_library(kth_largest STATIC ${CMAKE_CURRENT_SOURCE_DIR}/k_largest.cpp)
target_include_directories(kth_largest PUBLIC ${CMAKE_SOURCE_DIR}/utility)

# Define the executable with source files
add_executable(${EXE_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_libraries(${EXE_NAME} kth_largest)

# Correct include directories (use the folder, not the header file)
target_include_directories(${EXE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# target_include_directories(${EXE_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/utility)
