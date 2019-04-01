
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
#include "Powerplant/HousesAndCities/Houses.h"
#include "Powerplant/Card/Powerplant.h"
#include "Powerplant/Card/Deck.h"
#include "Powerplant/Resource/Resource.h"
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

    std::cout << "----------------------------------------\n";
    std::cout << "          WELCOME TO POWERGRID!!        \n";
    std::cout << "----------------------------------------\n";

    std::cout << "\nPlease enter the number of the map you would like to play: \n";
    for (auto entry : filesystem::directory_iterator(path)) {
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
//    m.removeEdge(m.getEdges().at(0));
//    m.removeVertex(m.getVertices().at(0));
//    cout << m;
    std::vector<string> regions = m.getRegions();
    m.removeRegion(1);
    m.createSubgraphs();
    std::vector<Map> graphs = m.getSubgraphs();
    for(auto s : graphs) {
        cout << s;
    }

   cout << "Please enter the number of players(2-6): ";
   cin >> numPlayers;

   for(int j = 0; j < numPlayers; j++) {
       Player *p = new Player();
       players.push_back(*p);
       cout << "Please select a region: \n";
       for(int k = 0; k < regions.size(); k++) {
           cout << k + 1 << ") " << regions[k] << "\n";
       }
       cin >> regionNumber;
       regions.erase(regions.begin()+ regionNumber - 1);
   }




    Deck d = Deck();
    std::cout << d << "\n\n";
    d.shuffle();
    std::cout << d;


    /*
     *  PART 3 ASSIGNMENT 2
     */

    /*
     *  RESOURCE BUYING PHASE
     *  requires a resource market and players --> hard-coded below
     */

    std::cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout<<"\nWELCOME TO POWER GRID PHASE 3\n";
    std::cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    std::cout<<"\nCREATING OBJECTS FOR PHASE 3 OF ASSIGNMENT 2\n";
    std::cout<<"\nCREATING 2 PLAYERS, player1 & player2\n";

    //Create Players
    /*
    std::vector<Player> playersPhase3 = std::vector<Player>();
    Player p1 = Player( "player1" );
    Player p2 = Player( "player2" );
    playersPhase3.push_back( p1 );
    playersPhase3.push_back( p2 );
     */

    //Create Map
    MapLoaderB mapLoaderPart3 = MapLoaderB();
    Map mapPhase3 = mapLoaderPart3.buildMapB(files.at(mapFile - 1));           //ERROR HERE
    Map *mapPhase3Ptr = &mapPhase3;
    std::cout<<"\nThe map has been created for phase 3\n";

    //Create Resource Market
    ResourceMarket resMarket = ResourceMarket();
    ResourceMarket *resMarketPtr = &resMarket;

    //Give Power Plants To Player 2
    std::cout<<"\nPowerplants for player2 are being placed into his/her possesion for demoing's Part 3, buying resources\n";


    for ( int i = 0 ; i < players.size() ; i++ )
        players.at(i).buyResources( resMarketPtr );

    /*
     *  HOUSE BUILDING PHASE
     *  requires a map, resource market and players --> hard-coded below
     */

    //Source of input parameters above
    //map: m
    //gamePhase: 1
    for ( int i = 0 ; i < players.size() ; i++ )
        players.at(i).buyCities( mapPhase3Ptr, 1 );

    std::cout<<"\nPart 3 of PowerGrid has ended\n";

    /*
     *  END OF PART 3 ASSIGNMENT 2
     */


    return 0;
}// close main loop