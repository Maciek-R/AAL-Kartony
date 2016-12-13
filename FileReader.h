#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <fstream>
#include <iostream>
#include "Box.h"
using namespace std;

class FileReader {
private:
	fstream file;

public:
	FileReader(char *);
	~FileReader();
	int readFromFile(vector<Box *>&);	//return numberOfBoxes
	bool good();


};

#endif