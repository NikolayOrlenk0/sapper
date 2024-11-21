cmake_minimum_required(VERSION 3.28)
project(interface)

set(CMAKE_CXX_STANDARD 17)
set (FLTK_INCLUDE_DIR "fltk-1.3.8")
add_executable(sapper
        src/main.cpp
        lib/Graph_lib/Graph.cpp
        lib/Graph_lib/GUI.cpp
        lib/Graph_lib/Window.cpp
        lib/vec/vec2d.cpp
        lib/poly/poly.cpp
        lib/Graph_lib/ext/graph.cpp
        )

set(TARGET "sapper")
find_package(FLTK 1.3.8)
find_library(COCOA_LIBRARY Cocoa)

include_directories(SYSTEM ${FLTK_INCLUDE_DIR})
include_directories("lib")
target_link_libraries(${TARGET} ${FLTK_LIBRARIES})

install(TARGETS ${TARGET})