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

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "FileReader.h"
#include "../Map/Map.h"

namespace Mike {

	class MapLoaderB {
	public:
		MapLoaderB();
		virtual ~MapLoaderB();

		Map buildMapB(std::string s);
		std::vector<string> getMapInfoB(std::string s);
	};//close class

} // close namespace

#endif /* MAPLOADERB_H_ */