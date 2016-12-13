#include "Box.h"

//int Box::N = 10;
int Box::count = 0;

//int Box::min = 1;
//int Box::max = 20;
//int Box::precision = 2;

Box::Box(float a, float b, float c) {
	length = a;
	width = b;
	height = c;
	ID = Box::count++;

	this->volume = a*b*c;
	normalise();
}

void Box::normalise() {
	float sides[3] = { length, width, height };
	std::sort(sides, sides+3);

	this->length = sides[0];
	this->width = sides[1];
	this->height = sides[2];
}

bool Box::isSmaller(Box* box) {

	if (length < box->getLength() && width < box->getWidth() && height < box->getHeight())
		return true;
	else {
		return false;
	}
}

std::ostream & operator<<(std::ostream & output, Box & box) {
	output << box.getID() << "\t" << box.getLength() << "\t" << box.getWidth() << "\t" << box.getHeight() << "\t" << box.getVolume() << std::endl;

	return output;
}

bool Box::cmp(Box* a, Box* b) { 

	if (a->getVolume() > b->getVolume())
		return true;
	else
		return false;
}

void Box::generate(vector<Box *> &boxes, int numberOfBoxes, int min, int max, int precision) {
	int precision_10 = 1;

	for (int i = 0; i < precision; ++i) {
		min *= 10;
		max *= 10;
		precision_10 *= 10;
	}
	
	for (int i = 0; i < numberOfBoxes; ++i) {
		float a = (float(rand() % (max - min)) + min) / precision_10;
		float b = (float(rand() % (max - min)) + min) / precision_10;
		float c = (float(rand() % (max - min)) + min) / precision_10;

		boxes.push_back(new Box(a, b, c));
	}
}


int Box::getID() const {
	return ID;
}
float Box::getLength() const {
	return length;
}
float Box::getWidth() const {
	return width;
}
float Box::getHeight() const {
	return height;
}
float Box::getVolume(){
	return volume;
}
