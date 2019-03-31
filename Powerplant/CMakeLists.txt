cmake_minimum_required(VERSION 3.13)
project(Powerplant)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES newMain.cpp Market/PowerplantMarket.cpp
        Market/ResourceMarket.cpp  Card/Powerplant.cpp
        GameAndPlayer/Player.cpp Market/ResourceMarket.cpp GameAndPlayer/Game.cpp
        Card/Step13.cpp Card/Card.cpp Card/Deck.cpp)
#set(SOURCE_FILES ../MainPractice.cpp)
add_executable(Powerplant ${SOURCE_FILES})
#add_executable(Powerplant ${SOURCE_FILES})
