#ifndef DEF_BATON
#define DEF_BATON

#include "Sort.h"
#include "Mage.h"
#include <string>

using namespace std;

class Baton
{
public:
	Baton();
	Baton(Sort* sort[4]);
	void lancerSort(char type, Mage* target);
	string getNom();
private:
	string m_nom;
	Sort* m_sorts[2];
};
#endif


