
/*
 * Main_PowerGrid_Driver.cpp
 *
 * 	MICHAEL GARNER
 * 	26338739
 * 	COMP 445
 * 	WINTER 2019
 *
 * 	ASSIGNMENT 1
 * 	POWER GRID
 *
 */


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>

#include <filesystem>

//Include classes in other files
#include "Map/Map.h"
#include "Powerplant/GameAndPlayer/Player.h"
#include "FileReader/MapLoader.h"
#include "Powerplant/Card/Powerplant.h"
#include "Powerplant/Card/Deck.h"
#include "Powerplant/GameAndPlayer/Player.h"
#include "Powerplant/Market/PowerplantMarket.h"

//Name Space
using namespace Mike;

int main() {
    int i = 1;
    int mapFile = 0;
    int numPlayers = 0;
    int regionNumber = 0;
    string path = "../MapFiles/";
    std::vector<string> files = std::vector<string>();
    std::vector<Player> players = std::vector<Player>();
    std::vector<string> regionsUsed;

    std::cout << "----------------------------------------\n";
    std::cout << "          WELCOME TO POWERGRID!!        \n";
    std::cout << "----------------------------------------\n";

    std::cout << "\nPlease enter the number of the map you would like to play: \n";
    for (const auto& entry : filesystem::directory_iterator(path)) {
        files.push_back(entry.path().string());
        std::cout << i << ") " << entry.path().string().substr(12) << std::endl;
        i++;
    }
    cin >> mapFile;
    //Loading a map
    MapLoaderB ml = MapLoaderB();
    Map m = ml.buildMapB(files.at(mapFile - 1));
    //printing the loaded map
    cout << m;
    std::vector<string> regions = m.getRegions();
    cout << "Please enter the number of players(2-6): ";
    cin >> numPlayers;
    for(int j = 0; j < numPlayers; j++) {
        auto *p = new Player();
        players.push_back(*p);
        cout << "Please select a region: \n";
        for(int k = 0; k < regions.size(); k++) {
            cout << k + 1 << ") " << regions[k] << "\n";
        }
        cin >> regionNumber;
        regionsUsed.push_back(regions.at(regionNumber - 1));
        regions.erase(regions.begin()+ regionNumber - 1);
    }
    m.createFinalMap(regionsUsed);
    for(string s : m.getRegions()) {
        cout << s << "\n";
    }

//    Deck d = Deck();
//    std::cout << d << "\n\n";
//    d.shuffle();
//    std::cout << d;
//    auto *rMarket = new ResourceMarket();
//    PowerplantMarket pMarket = PowerplantMarket(d);
    return 0;
}// close main loop