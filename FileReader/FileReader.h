/*
 * FileReader.h
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

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#ifndef FILEREADER_H_
#define FILEREADER_H_

class File_Reader {
public:
	File_Reader();
	virtual ~File_Reader();
    static std::vector<std::string> getLines(std::string& s);
};//close class

#endif /* FILEREADER_H_ */
