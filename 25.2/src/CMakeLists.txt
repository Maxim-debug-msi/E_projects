cmake_minimum_required(VERSION 3.19)

set(MY_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(25_2 main.cpp cpu.cpp  disk.cpp  gpu.cpp kbd.cpp  ram.cpp)

target_include_directories(25_2 PUBLIC ${MY_DIR})
