cmake_minimum_required(VERSION 2.6)
project(breakout)

add_executable(breakout main.cpp)

install(TARGETS breakout RUNTIME DESTINATION bin)
