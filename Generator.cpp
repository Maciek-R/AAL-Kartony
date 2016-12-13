#include "Generator.h"

std::vector<int> Generator::Nums;

void Generator::generateDate() {
	for (int i = 0; i < 1000000; ++i) {
		Nums.push_back(rand() % 10 + 1);
	}
}