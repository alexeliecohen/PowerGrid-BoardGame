/*
 * MapLoader.cpp
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
#include "Map.h"
#include "Vertex.h"
#include "Edge.h"

using std::vector;
using std::cout;
using std::endl;

namespace Mike {

//Gets a vector containing all of the strings from the file
vector<string> MapLoader::getMapInfo(){
	//Variables
	//File being used in File_Reader class
	File_Reader fw;
	vector<string> words = fw.getLines();
	return words;
}//close getMapInfo

//Uses mapFile.txt to load all data
Map MapLoader::buildMap() {
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
	fileInput = getMapInfo();

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

	cout << "Am I getting to this line? 0\n" ;
	//READ IN EDGES
	//Update variable
	cout << "Am I getting to this line? 1\n" ;
	cityC1 = fileInput.at( iCount );
	cout << "Am I getting to this line? 2\n" ;
	iCount++;
	Vertex v1 = returnMap.findVertex( cityC1 ); 		//ERROR LOCATED WITH findVertex
	cout << "Am I getting to this line? 3\n" ;
	Vertex &v1r = v1;
	cityC2 = fileInput.at( iCount );
	iCount++;
	Vertex v2 = returnMap.findVertex( cityC2 );
	Vertex &v2r = v2;
	connectionCost = std::stoi( fileInput.at( iCount ) );	//std::stoi( STR ) Converts string to integer type
	iCount++;
	cout << "Am I getting to this line? 4\n" ;

	while (iCount < (int) fileInput.size() ){
		cout << "v1r = " << v1r.getName() << endl ;
		cout << "v2r = " << v2r.getName() << endl ;
		cout << "connectionCost = " << connectionCost << endl ;
		//add edge to map
		returnMap.addEdge( v1r, v2r, connectionCost );
		cout << "Am I getting to this line? 6\n" ;
		//Update all values for next iteration
		cityC1 = fileInput.at( iCount );
		iCount++;
		Vertex v1 = returnMap.findVertex( cityC1 );
		v1r = v1;
		cityC2 = fileInput.at( iCount );
		iCount++;
		Vertex v2 = returnMap.findVertex( cityC2 );
		v2r = v2;
		connectionCost = std::stoi( fileInput.at( iCount ) );	//std::stoi( STR ) Converts string to integer type
		iCount++;
		cout << "Am I getting to this line? 7\n" ;
	}//close WHILE read in connections while there are still contents in the file


	if (validMap)
		cout << "\n\nThe Map loader is now returning a valid map\n\n";
	else
		cout << "\n\nTHE MAP LOADER READ AN INVALID MAP TYPE FILE\nPLEASE LOAD A VALID MAP FILE!\n\n";
	//return map
	return returnMap;
}//close map builder

MapLoader::MapLoader() {}
MapLoader::~MapLoader() {}

} /* namespace Mike */
