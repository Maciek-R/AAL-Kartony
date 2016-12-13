#include "Pack.h"

int Pack::N = 0;

Pack::Pack() {
	ID=++Pack::N;
}
Pack::~Pack() {
	/*for (int i = 0; i < boxes.size(); ++i) {
		delete boxes[i];
	}*/
	boxes.clear();
}

void Pack::addBox(Box * box) {
	boxes.push_back(box);
}
Box * Pack::getLastBox() {
	return boxes[boxes.size() - 1];
}
Box * Pack::getBox(unsigned i) {
	return boxes[i];
}
size_t Pack::size() const {
	return boxes.size();
}
int Pack::getID() const {
	return ID;
}

std::ostream & operator<<(std::ostream & output, Pack & pack) {
	output << "------------------Pack ";
	output << pack.ID;
	output << "--(";
	output << pack.boxes.size();
	if(pack.boxes.size() > 1)
		output << " " << "boxes)------------------\n";
	else
		output << " " << "box)--------------------\n";
	for (int i = 0; i < pack.size(); ++i) {
		output << *pack.boxes[i];
	}

	return output;
}
bool Pack::cmp(Pack* a, Pack* b) {

	if (a->getLastBox()->getVolume() > b->getLastBox()->getVolume())
		return true;
	else
		return false;
}
void Pack::clean() {
	boxes.clear();
}