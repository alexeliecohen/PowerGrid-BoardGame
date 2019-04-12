cmake_minimum_required(VERSION 3.13)
project(COMP345Team21)

set(CMAKE_CXX_STANDARD 17)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

set(Qt5Charts_DIR  "C:\\Qt\\5.12.2\\mingw73_64\\lib\\cmake\\Qt5Charts")
set(Qt5Widgets_DIR  "C:\\Qt\\5.12.2\\mingw73_64\\lib\\cmake\\Qt5Widgets")
set(Qt5Core_DIR  "C:\\Qt\\5.12.2\\mingw73_64\\lib\\cmake\\Qt5Core")

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Charts CONFIG REQUIRED)

include_directories(FileReader)
include_directories(Map)
include_directories(Powerplant/Card)
include_directories(Powerplant/GameAndPlayer)
include_directories(Powerplant/Market)
#include_directories(UI)

set(SOURCE
        FileReader/FileReader.cpp
        FileReader/FileReader.h
        FileReader/MapLoader.cpp
        FileReader/MapLoader.h
        Map/Edge.cpp
        Map/Edge.h
        Map/Map.cpp
        Map/Map.h
        Map/Vertex.cpp
        Map/Vertex.h
        Powerplant/Card/Card.cpp
        Powerplant/Card/Card.h
        Powerplant/Card/Deck.cpp
        Powerplant/Card/Deck.h
        Powerplant/Card/Powerplant.cpp
        Powerplant/Card/Powerplant.h
        Powerplant/Card/Step13.cpp
        Powerplant/Card/Step13.h
        Powerplant/Card/Summary.cpp
        Powerplant/Card/Summary.h
        Powerplant/GameAndPlayer/Subject.h
        Powerplant/GameAndPlayer/Subject.cpp
        Powerplant/GameAndPlayer/Game.cpp
        Powerplant/GameAndPlayer/Game.h
        Powerplant/GameAndPlayer/Observer.h
        Powerplant/GameAndPlayer/Observer.cpp
        Powerplant/GameAndPlayer/Player.cpp
        Powerplant/GameAndPlayer/Player.h
        Powerplant/Market/PowerplantMarket.cpp
        Powerplant/Market/PowerplantMarket.h
        Powerplant/Market/ResourceMarket.cpp
        Powerplant/Market/ResourceMarket.h
#        Powerplant/Market/ResourceMarket.h
        mainwindow.cpp
        Main_PowerGrid_Driver.cpp
        )
# Tell CMake to create the helloworld executable
#add_executable(${PROJECT_NAME} ${UI_HEADERS} ${SOURCE})
add_executable(COMP345Team21 WIN32 ${SOURCE})

# Use the Widgets module from Qt 5
target_link_libraries(COMP345Team21 Qt5::Widgets)
target_link_libraries(COMP345Team21 Qt5::Core)
target_link_libraries(COMP345Team21 Qt5::Charts)