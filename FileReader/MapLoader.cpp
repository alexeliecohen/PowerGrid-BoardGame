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
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "FileReader.h"
#include "../Map/Map.h"
#include "../Map/Vertex.h"
#include "../Map/Edge.h"

using std::vector;
using std::cout;
using std::endl;

namespace Mike {

//Gets a vector containing all of the strings from the file
    vector<string> MapLoaderB::getMapInfoB(){
        //Variables
        //File being used in File_Reader class
        File_Reader fw;
        vector<string> words = fw.getLines();
        return words;
    }//close getMapInfo

//Uses mapFile.txt to load all data
    Map MapLoaderB::buildMapB() {
        //Declare variables
        vector<string> fileInput;
        Map returnMap;
        bool validMap = true;
        string nextCity;
        string nextRegion;
        int iCount = 3;
        string cityC1, cityC2;
        int connectionCost;

        //Get file contents
        fileInput = getMapInfoB();

        //Authorize file
        if ( !(fileInput.at(0) == ("AUTHORIZEDPOWERGRIDMAP") )) {
            cout << "MAP LOADER ERROR - THE FILE BEING USED IS NOT AN AUTHORIZED MAP FILE" << endl;
            validMap = false;
        }//close if not authorized file

        //READ IN CITIES
        nextCity = fileInput.at(2);
        nextRegion = fileInput.at(3);
        while (nextCity != "CONNECTIONS"){
            //create vertex
            Vertex *vtx = new Vertex( nextCity, nextRegion);
            //add vertex to map
            returnMap.addVertex( *vtx );
            //Update all values for next iteration
            iCount++;
            nextCity = fileInput.at( iCount );
            iCount++;
            nextRegion = fileInput.at(iCount);
        }//close read in cities until CONNECTIONS IS  READ

        //backtrack the counter by 1 place
        cout << "\nFinished reading in cities, now reading in the connections\nThe iCount is currently reading from ";
        iCount--;
        cout << fileInput.at( iCount ) << endl << endl ;
        iCount++;

        //NEW CODE BELOW****************************************************************************************
        vector<Vertex> vlist1;
        vector<Vertex> vlist2;
        int vlistCounter = 0;

        //READ IN EDGES
        //Update variable
        cityC1 = fileInput.at( iCount );
        iCount++;
        vlist1.push_back( returnMap.findVertex( cityC1 ) );
        cityC2 = fileInput.at( iCount );
        cout << "cityC2 = " << cityC2 << endl ;
        vlist2.push_back( returnMap.findVertex( cityC2 ) );
        iCount++;
        connectionCost = std::stoi( fileInput.at( iCount ) );	//std::stoi( STR ) Converts string to integer type
        iCount++;
        cout << "NOW ENTERING WHILE LOOP\niCount = " << iCount << "\nfileSize = " << (int) fileInput.size() << endl;

        while (iCount < (int) fileInput.size() ){
            cout << "vlist1 = " << vlist1.at(vlistCounter) << endl ;
            cout << "vlist2 = " << vlist2.at(vlistCounter) << endl ;
            cout << "connectionCost = " << connectionCost << endl ;

            //add edge to map
            returnMap.addEdge( vlist1.at(vlistCounter), vlist2.at(vlistCounter), connectionCost );

            //Update all values for next iteration
            cityC1 = fileInput.at( iCount );
            iCount++;
            vlistCounter++;
            vlist1.push_back( returnMap.findVertex( cityC1 ) );

            cityC2 = fileInput.at( iCount );
            iCount++;
            vlist2.push_back(returnMap.findVertex( cityC2 ) );
            connectionCost = std::stoi( fileInput.at( iCount ) );	//std::stoi( STR ) Converts string to integer type
            iCount++;
        }//close WHILE read in connections while there are still contents in the file

        //NEW CODE ABOVE ****************************************************************************************


        if (validMap)
            cout << "\n\nThe Map loader is now returning a valid map\n\n";
        else
            cout << "\n\nTHE MAP LOADER READ AN INVALID MAP TYPE FILE\nPLEASE LOAD A VALID MAP FILE!\n\n";
        //return map
        return returnMap;
    }//close map builder

    MapLoaderB::MapLoaderB() {}
    MapLoaderB::~MapLoaderB() {}

} /* namespace Mike */