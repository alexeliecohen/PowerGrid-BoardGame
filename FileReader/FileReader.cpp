/*
 * FileReader.cpp
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


#include "FileReader.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>

using std::string;
using std::cout;
using std::vector;


namespace Mike {

//ATTRIBUTES
string fileName = "../FileReader/file";

//METHODS
vector<string> File_Reader::getLines(){
	//Declare variables
	vector<string> fileContent;			//fileContent = {"do", "re", "mi"};
	std::ifstream fileStream;
	string line;

	//open file
	fileStream.open("../FileReader/file");

	while(!fileStream.eof()){
		fileStream >> line;
		fileContent.push_back( line );
	}//close while not end of file

	//Print function closing results
		 std::cout << "The file contains " << fileContent.size() << " lines\n" ;
		//Print results before returning string array
		std::cout << "The FileReader.getLines function will display its string array values before returning them: " << std::endl ;
		for (int i = 0 ; i < (int) fileContent.size() ; i++){
			std::cout << fileContent.at(i) << std::endl ;
		}//close for
		fileStream.close();
	return fileContent;
}//close get file content
string File_Reader::getName() { return fileName; }

//CONSTRUCTORS
File_Reader::File_Reader() {}//close constructor
File_Reader::File_Reader(string fName) { fileName = fName; }//close constructor
File_Reader::~File_Reader() {} //close constructor

};//close name space Mike
