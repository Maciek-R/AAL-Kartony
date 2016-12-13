#include "FileWriter.h"


FileWriter::FileWriter(char * fileName) {

	file.open(fileName, std::ios::out);
	if (!file.good()) {


		cout << "Nie udalo sie otworzyc pliku" << endl;
		
	}
}
FileWriter::~FileWriter() {

	file << "==============================================\n";
	file.close();
}

void FileWriter::saveToFile(Pack * pack) {

	if (file.good()) {
	
		file << *pack;
	}

}

void FileWriter::writeTitle(float time, float percent, int numberOfBoxes) {

	file << "NUMBER OF BOXES\t\t\t"			    << numberOfBoxes << "\n";
	file << "TIME OF PACKING\t\t\t"				<< time << "s\n";
	file << "NUMBER OF PACKS\t\t\t"				<< Pack::N << "\n";
	file << "FREE SPACE\t\t\t"					<< percent << "%\n";

	file << "----------------------------------------------\n";
	file << "ID\tLENGTH\tWIDTH\tHEIGHT\tVOLUME\n";
	file << "----------------------------------------------\n";
	file << "==============================================\n";
}