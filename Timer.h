#ifndef TIMER_H
#define TIMER_H

#include <ctime>

class Timer {
public:

	static clock_t begin, end;

	static void timerStart();
	static float timerStop();

};


#endif