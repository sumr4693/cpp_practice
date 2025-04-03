cmake_minimum_required(VERSION 3.0.0)
project(memory_functions)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

# set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

set(SOURCE
    ${CMAKE_SOURCE_DIR}/allocs.c
)

add_library(mem STATIC ${SOURCE})

# Define the executable with source files
add_executable(memory_fun ${CMAKE_SOURCE_DIR}/main.cpp)

target_link_libraries(memory_fun mem)

# Correct include directories (use the folder, not the header file)
target_include_directories(memory_fun PUBLIC ${CMAKE_SOURCE_DIR})
