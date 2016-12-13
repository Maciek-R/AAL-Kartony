#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>
#include <fstream>
#include <iostream>
#include "Pack.h"
using namespace std;

class FileWriter {
private:
	fstream file;

public:
	FileWriter(char *);
	~FileWriter();
	void saveToFile(Pack *);
	void writeTitle(float, float, int);
};


#endif