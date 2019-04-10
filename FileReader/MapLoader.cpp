
/*
 * MapLoaderB.cpp
 *
 * 	MICHAEL GARNER
 * 	26338739
 * 	COMP 345
 * 	WINTER 2019
 *
 * 	ASSIGNMENT 1
 * 	POWER GRID
 *
 */

#include "MapLoader.h"

//Gets a vector containing all of the strings from the file
std::vector<std::string> MapLoaderB::getMapInfoB(std::string& s){
    //Variables
    //File being used in File_Reader class
    File_Reader fw;
    std::vector<std::string> words = File_Reader::getLines(s);
    return words;
}//close getMapInfo

//Uses mapFile.txt to load all data
    Map* MapLoaderB::buildMapB(std::string s) {
        //Declare variables
        std::vector<std::string> fileInput;
        Map* returnMap = Map::Instance();
        std::string nextCity;
        std::string nextRegion;
        std::string region;
        int iCount = 2;
        std::string cityC1, cityC2;

        //Get file contents
        fileInput = getMapInfoB(s);

        //Authorize file
        if ( !(fileInput.at(0) == ("AUTHORIZEDPOWERGRIDMAP") )) {
            std::cout << "MAP LOADER ERROR - THE FILE BEING USED IS NOT AN AUTHORIZED MAP FILE" << std::endl;
            std::cout << "Please enter a valid map file next time you play!";
            exit(0);
        }//close if not authorized file

        //READ IN REGIONS
        region = fileInput.at(iCount);
        while(region != "cities") {
            returnMap->addRegion(region);
            iCount++;
            region = fileInput.at(iCount);
        }
        iCount++;
        //READ IN CITIES
        nextCity = fileInput.at(iCount);
        iCount++;
        nextRegion = fileInput.at(iCount);
        iCount++;
        while (nextCity != "CONNECTIONS"){
            //create vertex
            auto *vtx = new Vertex( nextCity, nextRegion);
            //add vertex to map
            returnMap->addVertex( *vtx );
            //Update all values for next iteration
            nextCity = fileInput.at( iCount );
            iCount++;
            nextRegion = fileInput.at(iCount);
            iCount++;
        }//close read in cities until CONNECTIONS IS  READ
        //backtrack the counter by 1 place
        std::cout << "\nFinished reading in cities, now reading in the connections\nThe iCount is currently reading from ";
        iCount--;
        iCount--;
        std::cout << fileInput.at( iCount ) << std::endl << std::endl ;
        iCount++;
        do {
            std::string city1 = fileInput.at(iCount);
            Vertex u = returnMap->findVertex(city1);
            iCount++;
            std::string city2 = fileInput.at(iCount);
            Vertex v = returnMap->findVertex(city2);
            iCount++;
            int i = std::stoi(fileInput.at(iCount));
            iCount++;
            returnMap->addEdge(u, v, i);
        } while(iCount < fileInput.size());

        if (returnMap->BFS())
            std::cout << "\n\nThe Map loader is now returning a valid map\n\n";
        else {
            std::cout << "\n\nTHE MAP LOADER READ AN INVALID MAP TYPE FILE\nPLEASE LOAD A VALID MAP FILE!\n\n";
            std::cout << "The map entered is not connected, please try again with a connected map next time!";
            exit(0);
        }
        //return map
        return returnMap;
    }//close map builder

    MapLoaderB::MapLoaderB() = default;
    MapLoaderB::~MapLoaderB() = default;
