#include "MainProgram.h"

//int MainProgram::numberOfTests = 10;

MainProgram::MainProgram() {
	srand((unsigned int)time(0));
	//Timer::timerStart();

	
	//Box::generate(boxes);
	

}
float MainProgram::pack() {
	float space = 0;

	std::sort(boxes.begin(), boxes.end(), Box::cmp);

	bool inserted;

	for (int i = 0; i < boxes.size(); ++i) {
		inserted = false;

		for (int j = 0; j < packs.size(); ++j) {
			if (boxes[i]->isSmaller(packs[j]->getLastBox())) {

				packs[j]->addBox(boxes[i]);
				std::sort(packs.begin(), packs.end(), Pack::cmp);
				for (int p = 0; p < packs.size() - 1; ++p) {
					if (packs[p]->getLastBox()->getVolume() < packs[p + 1]->getLastBox()->getVolume()) {
						cout << "koniec" << endl;
						exit(0);
					}
				}
				space += boxes[i]->getVolume();

				inserted = true;
				break;
			}

		}
		if (!inserted) {
			createNewPack(boxes[i]);
		}


	}

	return space;
}
float MainProgram::pack2() {
	float space = 0;

	std::sort(boxes.begin(), boxes.end(), Box::cmp);

	bool inserted;

	for (int i = 0; i < boxes.size(); ++i) {
		inserted = false;

		for (int j = packs.size()-1; j >= 0; --j) {
			if (boxes[i]->isSmaller(packs[j]->getLastBox())) {

				packs[j]->addBox(boxes[i]);
				std::sort(packs.begin(), packs.end(), Pack::cmp);
				for (int p = 0; p < packs.size()-1; ++p) {
					if (packs[p]->getLastBox()->getVolume() < packs[p + 1]->getLastBox()->getVolume()) {
						cout << "koniec" << endl;
						exit(0);
					}
				}
			
				space += boxes[i]->getVolume();

				inserted = true;
				break;
			}

		}
		if (!inserted) {
			createNewPack(boxes[i]);
		}


	}
	//for (int p = 0; p < packs.size(); ++p)
		//cout << *packs[p] << endl;

	return space;
}

float MainProgram::getFreeSpaceInPercent(float space){
	float wholeVolume = 0;
	for (int i = 0; i < boxes.size(); ++i) {
		wholeVolume += boxes[i]->getVolume();
	}

	float percent = static_cast<float>(space) / wholeVolume;
	percent *= 100;
	return percent;
}


void MainProgram::runTestMode(char *fileNameOutput, int min, int max, int precision, int from, int to, int step, int numberOfTests) {

		
		
		/*for (int i = 0; i < boxes.size(); ++i) {
			cout << i << "   " << *boxes[i];
		}*/
	//FileWriter * fw = new FileWriter("results.txt");
	//fw->writeTitle(timeEnd, percent);
	//for (int i = 0; i < packs.size(); ++i) {
		//fw->saveToFile(packs[i]);
	//}
	//delete fw;

	vector<float>times;


	fstream file;
	file.open(fileNameOutput, std::ios::out);
	file << "n\t t(n)\t q(n)\n";

	float timeEnd;
	float averageTime;
	float sumTime = 0;
	for (int j = from; j <= to; j+=step) {
		std::cout << "Test dla " << j << " paczek" << std::endl;
		//Box::generate(boxes, j, min, max, precision);
		sumTime = 0;
		for (int i = 0; i < numberOfTests; ++i) {

			clearBoxes();
			clearPacks();
			
			
			Box::generate(boxes, j, min, max, precision);
			//std::cout << "-----Test " << i << std::endl;
			Timer::timerStart();
			float space = pack();
			timeEnd = Timer::timerStop();
			
			sumTime += timeEnd;
			//std::cout << "-----ZAOSZCZEDZONO " << space << std::endl;
			//std::cout << "-----Czas:			" << timeEnd << std::endl;

			float percent = getFreeSpaceInPercent(space);
			//std::cout << "-----ZAOSZCZEDZONO " <<setprecision(2)<<fixed<< percent << std::endl;
			
			//Box::generate(boxes);
		}
		std::cout << "Sredni czas: " << sumTime / numberOfTests << std::endl<<std::endl;
		float x = (sumTime / numberOfTests)*1000;
		times.push_back(x);
		//file << j << "\t" << x << "\n";

		//Box::N *= 10;
	//	boxes.clear();
		//Box::generate(boxes);

	}
	
	long long Tmed;
	int indexMed = (to - from) / step /2;
	long long N = (from + to) / 2;

	cout << "MED:" << indexMed << endl;
	//if (indexMed % 2 == 0) {
		Tmed = N*N;
		float tmed = times[indexMed];
	//}
		int j = from;
	for (int i = 0; i < times.size(); ++i) {
		
		long double T = j*j;
		
		long double q = (times[i] * Tmed)/(T*tmed);
		file << j << "\t" << times[i] << "\t"<< q<<"\n";
		j += step;
	}
		
	cout << Tmed << endl;
	file.close();

	/*	FileWriter * fw = new FileWriter("results.txt");
		fw->writeTitle(timeEnd, percent);
		for (int i = 0; i < packs.size(); ++i) {
			fw->saveToFile(packs[i]);
		}
		delete fw;	*/

		//return timeEnd;
	
}

int MainProgram::runReadFileMode(char * fileNameInput, char * fileNameOutput) {
	FileReader * fr = new FileReader(fileNameInput);
	int numberOfBoxes = fr->readFromFile(boxes);
	delete fr;

	if (!fr->good()) return -1;
	/*for (int i = 0; i < boxes.size(); ++i) {
		cout << *boxes[i] << endl;
	}*/

	Timer::timerStart();
	float space = pack();
	float timeEnd = Timer::timerStop();
	float percent = getFreeSpaceInPercent(space);

	FileWriter * fw = new FileWriter(fileNameOutput);
	fw->writeTitle(timeEnd, percent, numberOfBoxes);
	for (int i = 0; i < packs.size(); ++i) {
		fw->saveToFile(packs[i]);
	}
	delete fw;	

	return 0;
}

void MainProgram::runGenerateMode(char * fileNameOutput, int numberOfBoxes, int min, int max, int precision) {
	//odkomentowac
	//Box::generate(boxes, numberOfBoxes, min, max, precision);
	//
	/*for (int i = 0; i < boxes.size(); ++i) {
		cout << *boxes[i] << endl;
	}*/
	int q = 0;
	int w = 0;
	int r = 0;

	for (int i = 0; i < 10000; ++i) {
		//
		//usunac
		Box::generate(boxes, numberOfBoxes, min, max, precision);
		//

		//te powinno zostac
		Timer::timerStart();
		float space = pack();
		float timeEnd = Timer::timerStop();
		float percent = getFreeSpaceInPercent(space);
		//
		//te jest dodatkowe
		clearPacks();
		//cout << percent << endl;
		//cout << space << endl;

		float space2 = pack2();
		float percent2 = getFreeSpaceInPercent(space2);
		//cout << percent2 << endl;
		//cout << space2 << endl << endl;

		if (space > space2)	++q;
		else if (space2 > space) ++w;
		else ++r;
		//usunac
		clearBoxes();
		clearPacks();
		//
	}

	cout << "wynik" << endl;
	cout << q << endl;
	cout << w << endl;
	cout << r << endl;

	//
	//
	/*FileWriter * fw = new FileWriter(fileNameOutput);
	fw->writeTitle(timeEnd, percent, numberOfBoxes);
	for (int i = 0; i < packs.size(); ++i) {
		fw->saveToFile(packs[i]);
	}
	delete fw;*/
}

void MainProgram::createNewPack(Box * box) {
	Pack * pack = new Pack();
	pack->addBox(box);
	packs.push_back(pack);
}
void MainProgram::clearPacks() {
	for (int q = 0; q < packs.size(); ++q)
		delete packs[q];
	packs.clear();
}
void MainProgram::clearBoxes() {
	for (int q = 0; q < boxes.size(); ++q)
		delete boxes[q];
	boxes.clear();
}