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

#ifndef MAPLOADERB_H_
#define MAPLOADERB_H_

#include "FileReader.h"
#include "../Map/Map.h"

class MapLoaderB {
public:
    MapLoaderB();
    virtual ~MapLoaderB();
    static Map* buildMapB(std::string s);
    static std::vector<std::string> getMapInfoB(std::string& s);
};//close class


#endif /* MAPLOADERB_H_ */