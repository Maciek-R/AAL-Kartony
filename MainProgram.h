#ifndef MAINPROGRAM_H
#define MAINPROGRAM_H

#include <iostream>
#include "Box.h"
#include "Timer.h"
#include "Pack.h"
#include <vector>
#include "FileWriter.h"
#include "FileReader.h"
#include <fstream>
#include <iomanip>
using namespace std;

class MainProgram {
private:
	vector<Box *> boxes;
	vector<Pack *> packs;

	float pack();
	float pack2();
	float getFreeSpaceInPercent(float space);
	void createNewPack(Box *);
	void clearPacks();
	void clearBoxes();

	//static int numberOfTests;
public:
	MainProgram();
	int runReadFileMode(char *, char*);
	void runGenerateMode(char*, int, int, int, int);

	void runTestMode(char *, int, int, int, int, int, int, int);

};

#endif