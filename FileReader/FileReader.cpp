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
string fileName = "mapFile.txt";

//METHODS
vector<string> File_Reader::getLines(){
	//Declare variables
	vector<string> fileContent;			//fileContent = {"do", "re", "mi"};
	std::ifstream fileStream;
	string line;

	//open file
	fileStream.open("mapFile.txt");

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
/*
char[] File_Reader::getLines() {
	//Declare Variables
	//vector <string> returnStrings;
	vector<char> fileContents;
	string line;
	std::ifstream fileStream(fileName);

	//open file
	fileStream.open(fileName);
	//Read lines while there is a next line to read
	cout << "blaaa blaaa\n\n";

	while (fileStream.good()){
		fileStream >> fileContents;

	}//close while

	fileStream.close();

	//Print function closing results
	 std::cout << "The file contains " << fileContents.size() << " lines\n" ;
	//Print results before returning string array
	std::cout << "The FileReader.getLines function will display its string array values before returning them: " << std::endl ;
	for (int i = 0 ; i < (int) fileContents.size() ; i++){
		std::cout << fileContents.at(i) << std::endl ;
	}//close for

	//Return output
	return fileContents;
}//close get lines
*/
string File_Reader::getName() { return fileName; }

//CONSTRUCTORS
File_Reader::File_Reader() {}//close constructor
File_Reader::File_Reader(string fName) { fileName = fName; }//close constructor
File_Reader::~File_Reader() {} //close constructor



};//close name space Mike
