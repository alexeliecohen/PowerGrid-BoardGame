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

//METHODS
std::vector<std::string> File_Reader::getLines(std::string& s) {
	//Declare variables
	std::vector<std::string> fileContent;			//fileContent = {"do", "re", "mi"};
	std::ifstream fileStream;
	std::string line;

	//open file
	fileStream.open(s);

	while(!fileStream.eof()){
		fileStream >> line;
		fileContent.push_back( line );
	}//close while not end of file

	//Print function closing results
		 std::cout << "The file contains " << fileContent.size() << " lines\n" ;
		//Print results before returning string array
		std::cout << "The FileReader.getLines function will display its string array values before returning them: " << std::endl ;
		for (const auto & i : fileContent){
			std::cout << i << std::endl ;
		}//close for
		fileStream.close();
	return fileContent;
}//close get file content

//CONSTRUCTORS
File_Reader::File_Reader() = default;//close constructor
File_Reader::~File_Reader() = default; //close constructor

