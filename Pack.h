#ifndef PACK_H
#define PACK_H

#include <vector>

#include "Box.h"
using namespace std;

/**


*/
class Pack {
private:
	vector<Box *> boxes;
	int ID;
	
	friend std::ostream & operator<< (std::ostream & output, Pack & pack);
public:
	static int N;
	Pack();
	~Pack();
	void addBox(Box *);
	Box * getLastBox();
	Box * getBox(unsigned);
	size_t size() const;
	static bool cmp(Pack*, Pack*);
	int getID() const;
	void clean();
};

#endif