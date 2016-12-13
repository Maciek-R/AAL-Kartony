#include "Timer.h"

clock_t Timer::begin = 0;
clock_t Timer::end = 0;

void Timer::timerStart() {
	begin = clock();
}

float Timer::timerStop() {
	end = clock();

	return (end - begin) / (float)CLOCKS_PER_SEC;
}