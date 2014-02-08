cmake_minimum_required(VERSION 2.8)

project(abcpp)

include_directories(src)
include_directories(inc)

set(SOURCES src/graphanalysis.cpp src/graph.cpp)
set(HEADERS inc/graphanalysis.h inc/graph.h)

add_library(abcpp SHARED ${SOURCES} ${HEADERS})

install(TARGETS abcpp DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include)
