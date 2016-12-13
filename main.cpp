#include <iostream>
#include <conio.h>

#include "MainProgram.h"
#include "UserInterface.h"
#include <windows.h>
bool comp(int a, int b) {
	return a < b;
}

int main(int argc, char * argv[]) {

	UserInterface UI(argc, argv);
	UI.run();
	
	//MainProgram mainProgram;
	//std::cout << "\n" << mainProgram.run() << std::endl;


		/*
		Generator::generateDate();

		for (int a : Generator::Nums) {
			std::cout << a << std::endl;
		}

		std::cout << std::endl;

		std::sort(Generator::Nums.begin(), Generator::Nums.end(), comp);

		for (int a : Generator::Nums) {
			std::cout << a << std::endl;
		}
		*/
	//Timer::timerStart();

	/*for (int i = 0; i < 4000000000; ++i) {
		for (int i = 0; i < 2000000000000; ++i) {
			
		}
	}*/
	//Sleep(10000);
	//cout << "kon" << endl;
	//float f = Timer::timerStop();
	//cout << f << endl;

	_getch();
	return 0;

}