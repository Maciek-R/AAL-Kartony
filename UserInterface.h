#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "MainProgram.h"
#include "Box.h"

class UserInterface {

private:
	char * mode;
	char * fileNameInput;
	char * fileNameOutput;
	int numberOfBoxes;
	int min;					//minimalna dlugosc boku
	int max;					//maksymalna dlugosc boku
	int precision;				//liczba miejsc po przecinku
	int from;					//od ilu pudelek zaczynac testy
	int to;						//na jakiej ilosci pudelek konczyc test
	int step;					//przyrost pudelek w kazdym kolejnym tescie
	int numberOfTests;			//liczba testów dla ka¿dego kroku
	

	
public:
	UserInterface(int argc, char * argv[]);
	void run();
};


#endif