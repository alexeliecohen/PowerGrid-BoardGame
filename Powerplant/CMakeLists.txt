cmake_minimum_required(VERSION 3.13)
project(Powerplant)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp City.cpp Market.cpp Houses.cpp Powerplant.cpp Resource.cpp)


add_executable(Powerplant ${SOURCE_FILES})