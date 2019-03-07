cmake_minimum_required(VERSION 3.13)
project(Powerplant)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp HousesAndCities/City.cpp Market/Market.cpp HousesAndCities/Houses.cpp Card/Powerplant.cpp
        Resource/Resource.cpp GameAndPlayer/Player.cpp Market/ResourceMarket.cpp GameAndPlayer/Game.cpp
        Card/Step13.cpp Card/Card.cpp Card/Deck.cpp Card/Summary.cpp)
add_executable(Powerplant ${SOURCE_FILES})