cmake_minimum_required(VERSION 2.8)
project(unyt-automata-dfa)
add_executable(dfa main.cpp
	state.cpp
	state.h
	transition.cpp
	transition.h
	automaton.h
	automaton.cpp
	converter.cpp
	converter.h)
install(TARGETS dfa DESTINATION bin)