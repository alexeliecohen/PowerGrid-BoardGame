/*
 * MapLoader.h
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

#ifndef MAPLOADER_H_
#define MAPLOADER_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "FileReader.h"
#include "Map.h"

namespace Mike {

class MapLoader {
public:
	MapLoader();
	virtual ~MapLoader();

	Map buildMap();
	vector<string> getMapInfo();
};//close class

} // close namespace

#endif /* MAPLOADER_H_ */
