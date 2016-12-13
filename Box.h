#ifndef BOX_H
#define BOX_H

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Box {

private:
	float length;
	float width;
	float height;
	float volume;
	int ID;

	friend std::ostream & operator<< (std::ostream & output, Box & box);
public:
	Box(float, float, float);
	static int count;
	void normalise();
	bool isSmaller(Box * box);


	static bool cmp(Box *, Box *);
	static void generate(vector<Box *> & boxes, int, int, int, int);

	int getID() const;
	float getLength() const;
	float getWidth() const;
	float getHeight() const;
	float getVolume();	
};

#endif