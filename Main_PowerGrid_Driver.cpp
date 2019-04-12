
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include "Powerplant/GameAndPlayer/Game.h"
//#include <filesystem>

//Include classes in other files
#include "Map/Map.h"
#include "Powerplant/GameAndPlayer/Player.h"
#include "FileReader/MapLoader.h"
#include "Powerplant/Card/Powerplant.h"
#include "Powerplant/Card/Deck.h"
#include "Powerplant/GameAndPlayer/Player.h"
#include "Powerplant/Market/PowerplantMarket.h"
#include "mainwindow.h"
//Name Space


//#include "Display.h"

int main(int argc, char *argv[]) {

    Game *g = new Game(argc, argv);
    g->Phase1();
    g->Phase4();
//    g->add();
//    g->Notify();
//    display(argc, argv, g, 0);
//    display(argc, argv, g, 1);
//    clear();
//    display(argc, argv, g, 0);

}