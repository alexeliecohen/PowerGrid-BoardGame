cmake_minimum_required(VERSION 3.13)
project(COMP345Team21)

set(CMAKE_CXX_STANDARD 17)

include_directories(FileReader)
include_directories(Map)
include_directories(Powerplant/Card)
include_directories(Powerplant/GameAndPlayer)
include_directories(Powerplant/Market)

add_executable(COMP345Team21
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
        Powerplant/GameAndPlayer/Game.cpp
        Powerplant/GameAndPlayer/Game.h
        Powerplant/GameAndPlayer/Player.cpp
        Powerplant/GameAndPlayer/Player.h
        Powerplant/Market/PowerplantMarket.cpp
        Powerplant/Market/PowerplantMarket.h
        Powerplant/Market/ResourceMarket.cpp
        Powerplant/Market/ResourceMarket.h
        Main_PowerGrid_Driver.cpp
        )
