#include "FileReader.h"

FileReader::FileReader(char * fileName) {

	//std::cout << fileName << std::endl;
	file.open(fileName, std::ios::in);
	if (!file.good()) {


		cout << "Nie udalo sie otworzyc pliku" << endl;

	}
}
FileReader::~FileReader() {

	file.close();
}

int FileReader::readFromFile(vector<Box *>& boxes) {
	if (file.good()) {
		float a, b, c;
		int i = 0;

		while (!file.eof()) {
			++i;
			file >> a;
			file >> b;
			file >> c;

			boxes.push_back(new Box(a, b, c));
		}

		return i;
		
	}
	return 0;
}
bool FileReader::good() {
	return !file.good();
}