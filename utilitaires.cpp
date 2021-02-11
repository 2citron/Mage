#include "utilitaires.h"

int getRng(int min, int max) 
{
	std::random_device rd;
	std::mt19937 rng(rd());
	// dist1 sert à normaliser le nombre généré entre 1 et 100
	std::uniform_int_distribution<> dist(min, max);
	return dist(rng);
}

