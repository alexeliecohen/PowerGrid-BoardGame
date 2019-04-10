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
#include <cstdlib>


#ifndef FILEREADER_H_
#define FILEREADER_H_

using std::string;

class File_Reader {

private:
	string fileName;

public:
	File_Reader();
	File_Reader(string fName);
	virtual ~File_Reader();

	string getName();
	std::vector<string> getLines(std::string s);





};//close class

#endif /* FILEREADER_H_ */
