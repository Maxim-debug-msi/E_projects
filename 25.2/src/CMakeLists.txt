cmake_minimum_required(VERSION 3.19)

set(MY_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(25_2 main.cpp cpu.cpp ${MY_DIR}/cpu.h disk.cpp ${MY_DIR}/disk.h gpu.cpp
                ${MY_DIR}/gpu.h kbd.cpp ${MY_DIR}/kbd.h ram.cpp ${MY_DIR}/ram.h)
target_include_directories(25_2 PUBLIC ${MY_DIR})