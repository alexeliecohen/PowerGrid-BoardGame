cmake_minimum_required(VERSION 3.13)
project(COMP345Team21)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled
        Main_PowerGrid_Driver.cpp
        Map/Vertex.cpp
        Map/Edge.cpp
        Map/Map.cpp
        FileReader/FileReader.cpp
        FileReader/MapLoader.cpp
        Powerplant/Card/Card.cpp
        Powerplant/Card/Deck.cpp
        Powerplant/Card/Powerplant.cpp
        Powerplant/Card/Step13.cpp
        Powerplant/GameAndPlayer/Game.cpp
        Powerplant/GameAndPlayer/Player.cpp
        Powerplant/HousesAndCities/Houses.cpp
        Powerplant/Market/Market.cpp
        Powerplant/Market/PowerplantMarket.cpp
        Powerplant/Market/ResourceMarket.cpp
        Powerplant/Resource/Resource.cpp)