cmake_minimum_required(VERSION 2.8)
project(unyt-automata-dfa)
add_executable(dfa main.cpp)
install(TARGETS dfa DESTINATION bin)