#ifndef DEF_SORT
#define DEF_SORT

#include <string>
#include "Mage.h"

using namespace std;

class Sort
{
public:
	Sort();
	Sort(string nom, char type, int dmg);
	void agir(Mage* mage);
	string getNom();
	char getType();
private:
	string m_nom;
	char m_type;
	int m_dmg;
};
#endif