cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled
        Main_PowerGrid_Driver.cpp
        Map/Vertex.cpp
        Map/Edge.cpp
        Map/Map.cpp
        Powerplant/Player.cpp
        )