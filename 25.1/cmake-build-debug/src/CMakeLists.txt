cmake_minimum_required(VERSION 3.19)


set(MY_HEADER_DIR ${CMAKE_SOURCE_DIR}/headers)
add_executable(main.cpp ${MY_HEADER_DIR}/myt-lib.h myt-lib.cpp)
target_include_directories(25_1 PUBLIC ${MY_HEADER_DIR})