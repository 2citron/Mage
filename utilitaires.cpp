#include "utilitaires.h"

int getRng(int min, int max) 
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<> dist(min, max);
	return dist(rng);
}

