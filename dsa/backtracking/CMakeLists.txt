cmake_minimum_required(VERSION 3.10.0)
project(dsa_backtracking)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(SOURCE
    ${CMAKE_SOURCE_DIR}/backtracking.cpp
)

add_library(bt STATIC ${SOURCE})

set(RELEASE_NAME backtracking)
set(DEBUG_NAME backtracking_dbg)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(EXE_NAME ${DEBUG_NAME})
else()
    set(EXE_NAME ${RELEASE_NAME})
endif()

add_compile_options(
  "-Wall" "-Wpedantic" "-Wextra" "-fexceptions"
#   "$<$<CONFIG:Debug>:-O0;-g3;-ggdb>"
)

# Define the executable with source files
add_executable(${EXE_NAME} ${CMAKE_SOURCE_DIR}/main.cpp)

target_link_libraries(${EXE_NAME} bt)

# Correct include directories (use the folder, not the header file)
target_include_directories(${EXE_NAME} PUBLIC ${CMAKE_SOURCE_DIR})
