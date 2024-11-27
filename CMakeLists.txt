cmake_minimum_required(VERSION 3.28)
project(interface)

set(CMAKE_CXX_STANDARD 17)

add_executable(sapper
        lib/Graph_lib/Graph.cpp
        lib/Graph_lib/GUI.cpp
        lib/Graph_lib/Window.cpp
        lib/vec/vec2d.cpp
        lib/poly/poly.cpp
        lib/Graph_lib/ext/graph.cpp
        lib/table/bombs.cpp
        lib/table/table.cpp
#        tests/main.cpp
        src/main.cpp
        lib/table/grid/grid.h


)

set(TARGET "sapper")

find_package(FLTK 1.4 EXACT REQUIRED)
find_library(COCOA_LIBRARY Cocoa)

include_directories(SYSTEM ${FLTK_INCLUDE_DIR})
include_directories(SYSTEM lib)

target_link_libraries(${TARGET} ${FLTK_LIBRARIES})

install(TARGETS ${TARGET})