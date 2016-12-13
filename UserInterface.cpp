#include "UserInterface.h"

UserInterface::UserInterface(int argc, char * argv[]) {
	if (argc > 1) {

		if (strcmp(argv[1], "-f") == 0) {
			if (argc == 4) {
				this->mode = argv[1];
				this->fileNameInput = argv[2];
				this->fileNameOutput = argv[3];
			}
			else {
				cout << "Nieodpowiednia liczba argumentow!\n";
				cout << "-f nazwaPlikuWejsciowego nazwaPlikuWyjsciowego";
				exit(0);
			}
		}
		else if (strcmp(argv[1], "-g") == 0) {
			if (argc == 7) {
				this->mode = argv[1];
				this->fileNameOutput = argv[2];
				//Box::N = atoi(argv[3]);
				numberOfBoxes = atoi(argv[3]);
				min = atoi(argv[4]);
				max = atoi(argv[5]);
				precision = atoi(argv[6]);
			}
			else {
				cout << "Nieodpowiednia liczba argumentow!\n";
				cout << "-g nazwaPlikuWyjsciowego liczbaPudelek min max precyzja";
				exit(0);
			}
		}
		else if (strcmp(argv[1], "-t") == 0) {
			if (argc == 10) {
				this->mode = argv[1];
				this->fileNameOutput = argv[2];
				//Box::N = atoi(argv[3]);
				min = atoi(argv[3]);
				max = atoi(argv[4]);
				precision = atoi(argv[5]);
				from = atoi(argv[6]);
				to = atoi(argv[7]);
				step = atoi(argv[8]);
				numberOfTests = atoi(argv[9]);
			}
			else {
				cout << "Nieodpowiednia liczba argumentow!\n";
				cout << "-t nazwaPlikuWyjsciowego min max precyzja od do krok liczbaTestow";
				exit(0);
			}
			//cout << from << endl;

		}
	}
	else {
		cout << "Nie podano argumentow" << endl;
		cout << "Istnieja 3 tryby pracy:" << endl;
		cout << "-f Tryb odczytu z pliku\n";
		cout << "Skladnia: -f nazwaPlikuWejsciowego nazwaPlikuWyjsciowego\n";

		cout << "-g Tryb generacji danych\n";
		cout << "Skladnia: -g nazwaPlikuWyjsciowego liczbaPudelek min max precyzja\n";

		cout << "-t Tryb testow\n";
		cout << "Skladnia: -t nazwaPlikuWyjsciowego min max precyzja od do krok liczbaTestow\n";
		exit(0);
	}
}

void UserInterface::run() {
	if (mode == NULL) {
		std::cout << "Wybrano nieprawidlowy tryb" << std::endl;
		exit(0);
	}

	MainProgram mainProgram;

	if (strcmp(mode, "-f") == 0) {
		std::cout << "Wybrano tryb odczytu z pliku" << std::endl;
		bool f = mainProgram.runReadFileMode(fileNameInput, fileNameOutput);
		if(!f) std::cout << "Zakonczono pakowanie. Przejrzyj plik: " << fileNameOutput << std::endl;
		else cout << "as";

	}
	else if (strcmp(mode, "-g") == 0) {
		std::cout << "Wybrano tryb generacji danych" << std::endl;
		mainProgram.runGenerateMode(fileNameOutput, numberOfBoxes, min, max, precision);
		std::cout << "Zakonczono pakowanie. Przejrzyj plik: " << fileNameOutput << std::endl;
	}
	else if (strcmp(mode, "-t") == 0) {
		std::cout << "Wybrano tryb testow" << std::endl;
		mainProgram.runTestMode(fileNameOutput, min, max, precision, from, to, step, numberOfTests);
		std::cout << "Zakonczono Testy. Przejrzyj plik: " <<fileNameOutput << std::endl;
	}
	

}