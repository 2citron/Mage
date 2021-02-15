#ifndef DEF_BATON
#define DEF_BATON

#include "Sort.h"
#include <string>

using namespace std;

class Baton
{
public:
	Baton();
	Baton(Sort* sort[4]);
	int lancerSort(char type);
	string getNom();
private:
	string m_nom;
	Sort* m_sorts[2];
};
#endif


